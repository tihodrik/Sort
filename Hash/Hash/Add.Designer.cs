namespace Hash
{
    partial class Add
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.openHASH = new System.Windows.Forms.RadioButton();
            this.closeHASH = new System.Windows.Forms.RadioButton();
            this.hashTYPE = new System.Windows.Forms.GroupBox();
            this.content = new System.Windows.Forms.TextBox();
            this.addButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.mod = new System.Windows.Forms.TextBox();
            this.fillingTYPE = new System.Windows.Forms.GroupBox();
            this.randomINPUT = new System.Windows.Forms.RadioButton();
            this.userINPUT = new System.Windows.Forms.RadioButton();
            this.hashTYPE.SuspendLayout();
            this.fillingTYPE.SuspendLayout();
            this.SuspendLayout();
            // 
            // openHASH
            // 
            this.openHASH.AutoSize = true;
            this.openHASH.Checked = true;
            this.openHASH.Location = new System.Drawing.Point(20, 19);
            this.openHASH.Name = "openHASH";
            this.openHASH.Size = new System.Drawing.Size(77, 17);
            this.openHASH.TabIndex = 0;
            this.openHASH.TabStop = true;
            this.openHASH.Text = "Open hash";
            this.openHASH.UseVisualStyleBackColor = true;
            // 
            // closeHASH
            // 
            this.closeHASH.AutoSize = true;
            this.closeHASH.Location = new System.Drawing.Point(20, 42);
            this.closeHASH.Name = "closeHASH";
            this.closeHASH.Size = new System.Drawing.Size(77, 17);
            this.closeHASH.TabIndex = 1;
            this.closeHASH.Text = "Close hash";
            this.closeHASH.UseVisualStyleBackColor = true;
            // 
            // hashTYPE
            // 
            this.hashTYPE.Controls.Add(this.closeHASH);
            this.hashTYPE.Controls.Add(this.openHASH);
            this.hashTYPE.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.hashTYPE.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.hashTYPE.Location = new System.Drawing.Point(426, 7);
            this.hashTYPE.Name = "hashTYPE";
            this.hashTYPE.Size = new System.Drawing.Size(120, 74);
            this.hashTYPE.TabIndex = 2;
            this.hashTYPE.TabStop = false;
            this.hashTYPE.Text = "Hash type";
            // 
            // content
            // 
            this.content.Location = new System.Drawing.Point(12, 42);
            this.content.Multiline = true;
            this.content.Name = "content";
            this.content.Size = new System.Drawing.Size(397, 105);
            this.content.TabIndex = 3;
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(12, 162);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(397, 31);
            this.addButton.TabIndex = 4;
            this.addButton.Text = "Добавить";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(224, 17);
            this.label1.TabIndex = 5;
            this.label1.Text = "Введите числа для хэш-таблицы";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(420, 169);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 17);
            this.label2.TabIndex = 6;
            this.label2.Text = "mod =";
            // 
            // mod
            // 
            this.mod.Location = new System.Drawing.Point(473, 168);
            this.mod.Name = "mod";
            this.mod.Size = new System.Drawing.Size(69, 20);
            this.mod.TabIndex = 7;
            this.mod.Text = "10";
            // 
            // fillingTYPE
            // 
            this.fillingTYPE.Controls.Add(this.randomINPUT);
            this.fillingTYPE.Controls.Add(this.userINPUT);
            this.fillingTYPE.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.fillingTYPE.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fillingTYPE.Location = new System.Drawing.Point(426, 88);
            this.fillingTYPE.Name = "fillingTYPE";
            this.fillingTYPE.Size = new System.Drawing.Size(120, 74);
            this.fillingTYPE.TabIndex = 3;
            this.fillingTYPE.TabStop = false;
            this.fillingTYPE.Text = "Filling in type";
            // 
            // randomINPUT
            // 
            this.randomINPUT.AutoSize = true;
            this.randomINPUT.Location = new System.Drawing.Point(20, 42);
            this.randomINPUT.Name = "randomINPUT";
            this.randomINPUT.Size = new System.Drawing.Size(91, 17);
            this.randomINPUT.TabIndex = 1;
            this.randomINPUT.Text = "Random input";
            this.randomINPUT.UseVisualStyleBackColor = true;
            // 
            // userINPUT
            // 
            this.userINPUT.AutoSize = true;
            this.userINPUT.Checked = true;
            this.userINPUT.Location = new System.Drawing.Point(20, 19);
            this.userINPUT.Name = "userINPUT";
            this.userINPUT.Size = new System.Drawing.Size(80, 17);
            this.userINPUT.TabIndex = 0;
            this.userINPUT.TabStop = true;
            this.userINPUT.Text = "User\'s input";
            this.userINPUT.UseVisualStyleBackColor = true;
            // 
            // Add
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(565, 206);
            this.Controls.Add(this.fillingTYPE);
            this.Controls.Add(this.mod);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.content);
            this.Controls.Add(this.hashTYPE);
            this.Name = "Add";
            this.Text = "Form1";
            this.hashTYPE.ResumeLayout(false);
            this.hashTYPE.PerformLayout();
            this.fillingTYPE.ResumeLayout(false);
            this.fillingTYPE.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton openHASH;
        private System.Windows.Forms.RadioButton closeHASH;
        private System.Windows.Forms.GroupBox hashTYPE;
        private System.Windows.Forms.TextBox content;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox mod;
        private System.Windows.Forms.GroupBox fillingTYPE;
        private System.Windows.Forms.RadioButton randomINPUT;
        private System.Windows.Forms.RadioButton userINPUT;


    }
}

