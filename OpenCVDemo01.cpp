/*ʹ��filter2D�����Զ��������˲���,ͼ���ģ��
*/

#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;//�������ռ�
using namespace std;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("F:/OutPutResult/Test/Test/123.jpg");//��ȡһ��ͼƬ
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
			break;//����ESC�˳�����
		}
		kernel_size = 3 + 2 * (ind % 5);//�˲����˴�3�仯��8
		kernel = Mat::ones(kernel_size, kernel_size,CV_32F) / (float)(kernel_size*kernel_size);
		//Ӧ���˲���
		filter2D(src, dst,src.depth(),kernel);
		cout << "��ǰ�˲����ߴ�Ϊ��" << kernel_size << endl;
		imshow("�����˲���",dst);
		ind++;
	}
	return 0;
}
