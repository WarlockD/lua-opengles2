#include "ImageLoader.h"
#include "stb_image.h"
#include <assert.h>

ImageLoader::ImageLoader(const char*  filename) {
	clear();
	_filename = filename;
}

ImageLoader::~ImageLoader() {
	UnloadImage();
}
bool ImageLoader::LoadImage(int req_comp)
{
	assert(_data);
	_data = stbi_load(_filename.c_str(),&_width,&_height,&_channels,req_comp);
	if(!_data) _error = stbi_failure_reason();
	return _data == NULL;
}
void ImageLoader::UnloadImage() {
	if(_data) stbi_image_free(_data);
	clear();
}

