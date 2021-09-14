using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GM_CAD_lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        private void verticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Bitmap bitmap1 = new Bitmap(pictureBox1.Image);
            if (bitmap1 != null)
            {
                bitmap1.RotateFlip(RotateFlipType.Rotate180FlipY);
                pictureBox1.Image = bitmap1;
            }
        }

        private void horizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Bitmap bitmap1 = new Bitmap(pictureBox1.Image);
            if (bitmap1 != null)
            {
                bitmap1.RotateFlip(RotateFlipType.Rotate180FlipX);
                pictureBox1.Image = bitmap1;
            }
        }

        private void rotateLeftToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Bitmap bitmap1 = new Bitmap(pictureBox1.Image);
            if (bitmap1 != null)
            {
                bitmap1.RotateFlip(RotateFlipType.Rotate90FlipNone);
                bitmap1.RotateFlip(RotateFlipType.Rotate90FlipNone);
                bitmap1.RotateFlip(RotateFlipType.Rotate90FlipNone);
                pictureBox1.Image = bitmap1;
            }
        }

        private void rotateRightToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            Bitmap bitmap1 = new Bitmap(pictureBox1.Image);
            if (bitmap1 != null)
            {
                bitmap1.RotateFlip(RotateFlipType.Rotate90FlipNone);
                pictureBox1.Image = bitmap1;
            }
        }

        private void openToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            // Wrap the creation of the OpenFileDialog instance in a using statement,
            // rather than manually calling the Dispose method to ensure proper disposal
            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                dlg.Title = "Open Image";
                dlg.Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";

                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
                    PictureBox PictureBox1 = new PictureBox();

                    // Create a new Bitmap object from the picture file on disk,
                    // and assign that to the PictureBox.Image property
                    pictureBox1.Image = new Bitmap(dlg.FileName);

                    // Add the new control to its parent's controls collection
                    this.Controls.Add(PictureBox1);
                }
            }
        }

        private void saveToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                if (pictureBox1.Image != null)
                {
                    pictureBox1.Image.Save("myBitmap.bmp");
                }
            }
            catch (Exception)
            {
                MessageBox.Show("There was a problem saving the file." +
                    "Check the file permissions.");
            }
        }

        private void zoomToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            //pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox1.Image = ZoomPicture(pictureBox1.Image, new Size((pictureBox1.Width * 2),
                                                                        (pictureBox1.Height * 2)));
            pictureBox1.Width = Convert.ToInt32(pictureBox1.Width * 2);
            pictureBox1.Height = Convert.ToInt32(pictureBox1.Height * 2);
            //pictureBox1.Width = (int)(pictureBox1.Width * 2);
            //pictureBox1.Height = (int)(pictureBox1.Height * 2);
        }

        private void zoomToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;

            pictureBox1.Image = ZoomPicture(pictureBox1.Image, new Size((pictureBox1.Width / 2),
                                                                        (pictureBox1.Height / 2)));
            pictureBox1.Width = Convert.ToInt32(pictureBox1.Width / 2); 
            pictureBox1.Height = Convert.ToInt32(pictureBox1.Height / 2); 
            //pictureBox1.Width = (int)(pictureBox1.Width / 2);
            //pictureBox1.Height = (int)(pictureBox1.Height / 2);
        }

        Image ZoomPicture(Image img, Size size)
        {
            Bitmap bm = new Bitmap(img, Convert.ToInt32(size.Width),
                                    Convert.ToInt32(size.Height));
            Graphics gpu = Graphics.FromImage(bm);
            gpu.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
            return bm;
        }

    }
}
