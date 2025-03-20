#include <iostream>
#include <vector>
#include <random>
#include <time.h> 


using namespace std;

int main() {
	FILE* fp_r;
	FILE* fp_w;

	bool err_r = fopen_s(&fp_r, "AiPicG.bmp", "rb");
	bool err_w = fopen_s(&fp_w, "AIgened_x.bmp", "wb");
	if (err_r != 0 || err_w != 0)
		return 0;

	unsigned char c;
	for (int i = 0; i < 1078; i++)
	{
		c = getc(fp_r);
		putc(c, fp_w);
	}

	int w = 1024;
	int h = 1024;

	
	vector<vector<unsigned char>> imgArr;
	imgArr.resize(h, vector<unsigned char>(w));

	for (int i = h - 1; i >= 0; i--) 
	{  
		for (int j = 0; j < w; j++) 
		{
			imgArr[i][j] = getc(fp_r);
		}
	}


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int sum = 0, count = 0;

			int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
			int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

			for (int k = 0; k < 8; k++) 
			{
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (ni >= 0 && ni < h && nj >= 0 && nj < w) 
				{
					sum += imgArr[ni][nj];
					count++;
				}
			}

			imgArr[i][j] = (count > 0) ? (sum / count) : imgArr[i][j];
		}
	}


	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = 0;j < w;j++)
		{
			putc(imgArr[i][j], fp_w);
		}
	}


	return 0;
}

