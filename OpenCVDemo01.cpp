/*使用filter2D创建自定义线性滤波器,图像的模糊
*/

#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;//创建名空间
using namespace std;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("F:/OutPutResult/Test/Test/123.jpg");//读取一张图片
	if (!src.data) {
		printf("could not load image...");
		return -1;
	}
	imshow("input_image", src);
	Mat kernel;
	int c=0;
	int ind = 0;
	int kernel_size;
	while (true) {
		c = waitKey(500);
		if (c==27) {
			break;//按下ESC退出程序
		}
		kernel_size = 3 + 2 * (ind % 5);//滤波器核从3变化到8
		kernel = Mat::ones(kernel_size, kernel_size,CV_32F) / (float)(kernel_size*kernel_size);
		//应用滤波器
		filter2D(src, dst,src.depth(),kernel);
		cout << "当前滤波器尺寸为：" << kernel_size << endl;
		imshow("线性滤波器",dst);
		ind++;
	}
	return 0;
}
