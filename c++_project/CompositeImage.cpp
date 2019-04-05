#include "CompositeImage.h"
#include <iostream>

CompositeImage::CompositeImage()
{
}
CompositeImage::~CompositeImage()
{
}
CompositeImage::CompositeImage(Image a, Image b, float alpha):Image(a.get_w(), a.get_h())
{
if(a.get_w() == b.get_w() && a.get_h() == b.get_h())
		{
			for(int i = 0; i < _h; i++)
			{
				for(int j = 0; j < _w; j++)
				{
					Color c=alpha*(b.get_pr(i,j).get_c())+(1-alpha)*(a.get_pr(i,j).get_c());
					Pixel P(i,j,c);
					set_p(P,i,j);
				}
			}
    }
}
