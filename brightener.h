#pragma once
#include <cstdint>
#include <memory>
#include <iostream>

struct Image
{
	int m_rows;
	int m_columns;
	uint8_t* m_pixels; // max 1k x 1k image

	Image() = delete;

	Image(int rows, int columns) : m_rows(rows), m_columns(columns)
	{
		std::cout << "Image created" << std::endl;
		m_pixels = new uint8_t[rows * columns];
		memset(m_pixels, NULL, rows * columns);
	}

	~Image()
	{
		std::cout << "Image destroyed" << std::endl;
		delete m_pixels;
	}
};

class ImageBrightener
{
private:
	Image m_inputImage;
public:
	ImageBrightener(const Image& inputImage);
	ImageBrightener(Image&& inputImage);
	ImageBrightener() = default;

	int BrightenWholeImage();
	Image GetImage() const;
};
