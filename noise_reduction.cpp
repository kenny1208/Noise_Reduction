#include <iostream>
#include <vector>
#include <random>
#include <time.h> 


using namespace std;

int main() {
	FILE* fp_r;
	FILE* fp_w;
	FILE* fp_h;

	bool err_r = fopen_s(&fp_r, "AiPicG.bmp", "rb");
	bool err_w = fopen_s(&fp_w, "AIgened_x.bmp", "wb");
	bool err_h = fopen_s(&fp_h, "AIgened_y.bmp", "wb");
	if (err_r != 0 || err_w != 0)
		return 0;

	unsigned char c;

	for (int i = 0; i < 1078; i++) 
	{
		c = getc(fp_r);
		putc(c, fp_w);
		putc(c, fp_h);
	}


	int w = 1024;
	int h = 1024;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> noise_prob(1, 20);
	uniform_int_distribution<> black_or_white(0, 1);

	vector<vector<unsigned char>> imgArr;
	imgArr.resize(h, vector<unsigned char>(w));

	for (int i = 0; i < w * h; i++)
	{
		int x = i % w;
		int y = i / w;
		int pixel = getc(fp_r);

		if (noise_prob(gen) == 1)
		{
			pixel = (black_or_white(gen) == 0) ? 0 : 255;
		}

		imgArr[x][h - y - 1] = static_cast<unsigned char>(pixel);
	}

	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = 0; j < w; j++)
		{
			putc(imgArr[j][i], fp_w);
		}

	}

	fclose(fp_r);
	fclose(fp_w);

	err_w = fopen_s(&fp_w, "AIgened_x.bmp", "rb");

	vector<vector<unsigned char>> imgArr2;
	imgArr2.resize(h, vector<unsigned char>(w));

	for (int i = h - 1; i >= 0; i--) 
	{  
		for (int j = 0; j < w; j++) 
		{
			imgArr2[i][j] = getc(fp_w);
		}
	}


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int sum[9] = {};
			int count = 0;

			int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
			int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

			for (int k = 0; k < 8; k++) 
			{
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (ni >= 0 && ni < h && nj >= 0 && nj < w) 
				{
					sum[k] = imgArr[ni][nj];
					count++;
				}
			}
			sort(sum, sum + 9);	
			imgArr2[j][i] = sum[4];
		}
	}


	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = 0;j < w;j++)
		{
			putc(imgArr2[i][j], fp_h);
		}
	}


	return 0;
}

