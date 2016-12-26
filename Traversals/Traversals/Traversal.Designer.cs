namespace Traversals
{
    partial class Traversal
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.depth = new System.Windows.Forms.RadioButton();
            this.breadth = new System.Windows.Forms.RadioButton();
            this.type = new System.Windows.Forms.GroupBox();
            this.traverse = new System.Windows.Forms.Button();
            this.result = new System.Windows.Forms.TextBox();
            this.type.SuspendLayout();
            this.SuspendLayout();
            // 
            // depth
            // 
            this.depth.AutoSize = true;
            this.depth.Location = new System.Drawing.Point(24, 22);
            this.depth.Name = "depth";
            this.depth.Size = new System.Drawing.Size(97, 17);
            this.depth.TabIndex = 0;
            this.depth.TabStop = true;
            this.depth.Text = "Depth traversal";
            this.depth.UseVisualStyleBackColor = true;
            // 
            // breadth
            // 
            this.breadth.AutoSize = true;
            this.breadth.Location = new System.Drawing.Point(24, 46);
            this.breadth.Name = "breadth";
            this.breadth.Size = new System.Drawing.Size(105, 17);
            this.breadth.TabIndex = 1;
            this.breadth.TabStop = true;
            this.breadth.Text = "Breadth traversal";
            this.breadth.UseVisualStyleBackColor = true;
            // 
            // type
            // 
            this.type.Controls.Add(this.breadth);
            this.type.Controls.Add(this.depth);
            this.type.Location = new System.Drawing.Point(221, 12);
            this.type.Name = "type";
            this.type.Size = new System.Drawing.Size(131, 79);
            this.type.TabIndex = 2;
            this.type.TabStop = false;
            this.type.Text = "Traversal type";
            // 
            // traverse
            // 
            this.traverse.Location = new System.Drawing.Point(221, 110);
            this.traverse.Name = "traverse";
            this.traverse.Size = new System.Drawing.Size(131, 34);
            this.traverse.TabIndex = 3;
            this.traverse.Text = "Осуществить обход";
            this.traverse.UseVisualStyleBackColor = true;
            this.traverse.Click += new System.EventHandler(this.traverse_Click);
            // 
            // result
            // 
            this.result.Location = new System.Drawing.Point(13, 12);
            this.result.Multiline = true;
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(202, 132);
            this.result.TabIndex = 4;
            // 
            // Traversal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(358, 159);
            this.Controls.Add(this.result);
            this.Controls.Add(this.traverse);
            this.Controls.Add(this.type);
            this.Name = "Traversal";
            this.Text = "Traversal";
            this.type.ResumeLayout(false);
            this.type.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton depth;
        private System.Windows.Forms.RadioButton breadth;
        private System.Windows.Forms.GroupBox type;
        private System.Windows.Forms.Button traverse;
        private System.Windows.Forms.TextBox result;
    }
}