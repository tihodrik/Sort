using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace Hash
{
    delegate int HashFunction(int num);

    public partial class Add : Form
    {
        public List<int>[] hash;
        public int free;
        public int step = 3;

        Search searchForm;
        Delete delForm;
        TextBox result;

        public Add()
        {
            NativeMethods.AllocConsole();
            Console.ForegroundColor = ConsoleColor.Red;

            InitializeComponent();
            CreateResult();
        }

        public int HashFunction1(int num)
        {
            int m = hash.Count();
            return num % m;
        }
        public int HashFunction2(int num)
        {
            if (free == 0)
            {
                throw new OutOfMemoryException("Hash table is full. Impossible to add element " + num);
            }

            int m = hash.Count();
            int index = num % m;

            if (hash[index].Count == 0)
                return index;

            for (int i = 0; i < m; i++)
            {
                for (int j = 1; (index + i + j * step) % m != (index + i) % m; j++)
                {
                    if (hash[(index + i + j * step) % m].Count == 0)
                    {
                        return (index + i + j * step) % m;
                    }
                }
            }
            return -1;
        }

        /// <summary>
        /// Перезаполняет значения хэш-таблицы,
        /// значения берутся из поля content
        /// Так как обновление проходит программно, то
        /// обновления размера таблицы не происходит.
        /// Поэтому ее можно просто очистить, пересоздания не требуется
        /// </summary>
        public void RefreshAdd()
        {
            // Записываем размер хэш-таблицы
            // Обновление вызывается только после удаления элемента
            // Значит, размер хэш-таблицы не изменился
            int m = hash.Count();

            // Очишаем поле ввода элементов
            content.Clear();

            // Переписываем элементы хэш-таблицы в поле ввода
            bool first = true;
            foreach (var element in hash)
            {
                foreach (var num in element)
                {
                    if (first)
                    {
                        content.AppendText(num.ToString());
                        first = false;
                    }
                    else
                    {
                        content.AppendText(" " + num.ToString());
                    }
                }
            }

            // Для закрытого хэширования требуется пересчет
            if (closeHASH.Checked)
            {
                foreach (var element in hash)
                {
                    if (element.Count > 0)
                    {
                        element.RemoveAt(0);
                    }
                }

                free = m;

                List<string> numbers = content.Text.Split(' ').ToList<string>();

                // Заполнение хэш-таблицы
                for (int i = 0; i < numbers.Count(); i++)
                {
                    int num = int.Parse(numbers[i]);
                    int index = HashFunction2(num);
                    hash[index].Add(num);
                    free--;
                }
            }

            // Перепечатываем поле результатов
            result.Clear();
            FillHash(result);
        }
        private void FillHash(TextBox result)
        {
            StringBuilder str = new StringBuilder();
            int m = int.Parse(mod.Text);

            for (int i = 0; i < m; i++)
            {
                str.AppendFormat("{0}: ", i);
                foreach (var element in hash[i])
                {
                    str.AppendFormat("{0} ", element);
                }
                str.Append('\n');
                result.AppendText(str.ToString());
                str.Clear();
            }
        }
        private void CreateResult()
        {
            result = new TextBox();

            result.Name = "result";
            result.Height = 0;
            result.Font = new Font(result.Font.FontFamily, 10);
            result.Enabled = false;
            result.Visible = false;
            result.Multiline = true;
            result.Location = new Point(addButton.Location.X, addButton.Location.Y + 50);
            result.Width = addButton.Width;

            this.Controls.Add(result);
        }
        private bool AddRandom()
        {
            // Вызываем форму для ввода числа случайных чисел,
            // которые требуется сгенерировать
            RandomCOUNT random = new RandomCOUNT();
            random.ShowDialog(this);

            // Записываем введенное число в переменную count
            // Если ничего не введено или введено не число -  ничего не генерируем
            // и возвращаем сообщение об ошибке
            int count = 0;
            if (!int.TryParse(content.Text, out count))
            {
                return false;
            }

            // Очищаем поле ввода
            content.Clear();

            // Задаем генератор псевдослучайных чисел
            Random rand = new Random();

            // Записываем сгенерированные числа в нужном формате в поле content
            content.AppendText(rand.Next(1000).ToString());
            for (int i = 1; i < count; i++)
            {
                content.AppendText(" " + rand.Next(1000).ToString());
            }

            // Возвращаем сообщение об успешной генерации последовательности
            return true;
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            // Считываем размер хэш-таблицы
            int m = int.Parse(mod.Text);
            free = m;

            // Создание хэш-таблицы заданного размера
            hash = new List<int>[m];
            for (int i = 0; i < m; i++)
            {
                hash[i] = new List<int>();
            }

            // Блок рандомного заполнения
            if (randomINPUT.Checked)
            {
                if (!AddRandom())
                    return;
            }

            // Считывание введенных элементов
            List<string> numbers = content.Text.Split(' ').ToList<string>();
            bool removed = false;

            // Определение хэш-функции
            HashFunction Hash;

            if (openHASH.Checked)
            {
                Hash = HashFunction1;
            }
            else
            {
                Hash = HashFunction2;
            }

            // Заполнение хэш-таблицы
            for (int i = 0; i < numbers.Count(); i++)
            {
                int num;
                if (!int.TryParse(numbers[i], out num))
                {
                    return;
                }
                int index;
                try
                {
                    index = Hash(num);
                    hash[index].Add(num);
                    free--;
                }
                catch (OutOfMemoryException exception)
                {
                    numbers.RemoveAt(i);
                    i--;
                    removed = true;

                    Console.WriteLine(exception.Message);
                }
            }

            if (removed)
            {
                content.Clear();

                bool first = true;
                foreach (var element in numbers)
                {
                    if (first)
                    {
                        content.AppendText(element);
                        first = false;
                    }
                    else
                    {
                        content.AppendText(" " + element);
                    }

                }
            }

            // Отделяем лог
            Console.WriteLine("\n");

            // Создание блока для вывода хэш-таблицы
            var result = this.Controls.Find("result", false).First() as TextBox;
            result.Clear();

            if (result.Height == 0)
            {
                result.Visible = true;
                this.Height += (m * 18 + 5) + 20;
            }
            else
            {
                this.Height = this.Height - result.Height + (m * 18 + 5);
            }

            result.Height = m * 18 + 5;


            // Вывод хэш-таблицы
            FillHash(result);

            // Запуск диалога поиска
            searchForm = new Search(hash);
            searchForm.ShowDialog(this);

            // Запуск диалога удаленияы
            delForm = new Delete(hash);
            delForm.ShowDialog(this);

        }
    }
}
