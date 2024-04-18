#include "brightener.h"

ImageBrightener::ImageBrightener(const Image& inputImage) : m_inputImage(inputImage)
{
}

ImageBrightener::ImageBrightener(Image&& inputImage) : m_inputImage(inputImage)
{
}

int ImageBrightener::BrightenWholeImage()
{
	// For brightening, we add a certain grayscale (25) to every pixel.
	// While brightening, some pixels may cross the max brightness. They are
	// called 'attenuated' pixels
	int attenuatedPixelCount = 0;
	for (int x = 0; x < m_inputImage.m_rows; x++)
	{
		for (int y = 0; y < m_inputImage.m_columns; y++)
		{
			if (m_inputImage.m_pixels[x * m_inputImage.m_columns + y] > (255 - 25))
			{
				++attenuatedPixelCount;
				m_inputImage.m_pixels[x * m_inputImage.m_columns + y] = 255;
			}
			else
			{
				int pixelIndex = x * m_inputImage.m_columns + y;
				m_inputImage.m_pixels[pixelIndex] += 25;
			}
		}
	}
	return attenuatedPixelCount;
}

Image ImageBrightener::GetImage() const
{
	return m_inputImage;
}
