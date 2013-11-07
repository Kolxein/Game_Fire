#ifndef SIZE_H
#define SIZE_H

class Size
{
public:
	Size(int w, int h);
	bool operator==(const Size& rhs)const;
	int width;
	int height;
};

#endif
