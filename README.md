# Image Noise Reduction Tool

## Overview
This C++ program applies noise reduction to grayscale BMP images using a median filter technique. The application first adds random noise to an image and then applies the median filter to remove it, demonstrating the effectiveness of median filtering for noise reduction.

## How It Works
1. The program reads a grayscale BMP image file named "AiPicG.bmp"
2. It adds salt and pepper noise to the image (with a 1/20 probability for each pixel)
3. The noisy image is saved as "AIgened_x.bmp"
4. A median filter is applied to the noisy image, using an 8-neighborhood approach
5. The filtered image is saved as "AIgened_y.bmp"

## Features
- Salt and pepper noise generation
- Median filtering for noise reduction
- Preservation of image edges compared to simple blurring techniques

## Requirements
- Visual Studio (project built with VS 2022)
- Windows environment
- A grayscale BMP image file named "AiPicG.bmp" (1024x1024 pixels) placed in the same directory as the executable

## Building the Project
1. Open the `Noise_Reduction.sln` file in Visual Studio
2. Select the desired build configuration (Debug/Release) and platform (x86/x64)
3. Build the solution using Build > Build Solution or by pressing F7

## Usage
1. Place your input grayscale image named "AiPicG.bmp" in the same directory as the executable
2. Run the program
3. Two output files will be generated:
   - "AIgened_x.bmp" - The original image with random noise added
   - "AIgened_y.bmp" - The result after applying the median filter

## Limitations
- Only processes BMP files
- Input image must be grayscale and 1024x1024 pixels in size
- Input and output filenames are hardcoded
- Fixed noise probability (1/20)

## Future Improvements
- Add command-line arguments for input/output files
- Support for different image sizes and color images
- Adjustable noise level and filter parameters
- Support for additional image formats
- Add progress indicators for large images
