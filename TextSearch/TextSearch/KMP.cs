using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextSearch
{
    class KMP : SearchAlgorithm
    {
        public String Text { get; set; }
        public String Str { get; set; }

        public KMP(String text, String str)
        {
            Text = text;
            Str = str;
        }

        // Префикс - позиция, с элементом на которой совпадает текущий элемент
        public int[] GetPrefix(string str)
        {
            int[] res = new int[str.Length];
            res[0] = 0;
            int pos = 0;

            for (int i = 1; i < str.Length; i++)
            {
                while (pos >= 0 && str[pos] != str[i])
                {
                    pos--;
                }
                pos++;
                res[i] = pos;
            }
            return res;
        }

        public StringBuilder Search()
        {
            int res = -1;
            if (Text.Length == 0 || Str.Length > Text.Length)
            {
                return new StringBuilder().AppendFormat("Position: {0}, compared: {1} times", res, 0);
            }

            int[] d = GetPrefix(Str);
            int counter = 1;

            // Search
            int i = 0, j = 0;
            while (i < Text.Length && j < Str.Length)
            {
                while (j == 0 && Text[i] != Str[j])
                {
                    counter++;
                    i++;
                }
                while (j > 0 && Text[i] != Str[j])
                {
                    counter++;
                    i = i - j + d[j-1] + 1;
                    j = 0;
                    if (Text.Length - i < Str.Length)
                    {
                        return new StringBuilder().AppendFormat("Position: {0}, copmared: {1} times", -1, counter); ;
                    }
                }
                i++;
                j++;

                if (j == Str.Length)
                    res = i - j;
                else
                    res = -1;
            }
             return new StringBuilder().AppendFormat("Position: {0}, copmared: {1} times", res, counter); ;
        }
    }
}

