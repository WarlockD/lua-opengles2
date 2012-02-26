#pragma once

#include <string>

// Simple image wrapper
class ImageLoader {
protected:
	inline void clear() { _width = _height = _channels =0; _data=NULL; _error ="";  }
	int _width;
	int _height;
	int _channels;
	unsigned char* _data;
	std::string _error;
	std::string _filename;
public:
	typedef const unsigned char* ImageData;
	int width() const { return _width; }
	int height() const { return _height; }
	int channels() const { return _channels; }
	const char* error_str() const { return _error.c_str(); }
	const char* filename() const { return _filename.c_str(); }
	bool error() const { return _data == NULL; }
	ImageData data() const { return _data; }
	void setFilename(const char* filename) { UnloadImage(); _filename = filename; }
public:
	bool LoadImage(int req_comp=0);
	void UnloadImage();
	ImageLoader(const char* filename);
	~ImageLoader();
	bool operator==( const ImageLoader&r) const { return _filename == r._filename; }
	bool operator==( const char* r) const { return _filename == r; }
	bool operator==( const std::string&r) const { return _filename == r; }
	bool operator!=( const ImageLoader&r) const { return _filename != r._filename; }
	bool operator!=( const char* r) const { return _filename != r; }
	bool operator!=( const std::string&r) const { return _filename != r; }
};