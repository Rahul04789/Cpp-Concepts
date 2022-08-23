int (*fptr_Shape[2])(int);
int (*fptr_Circle[2])(int);
int (*fptr_Rectangle[2])(int);
struct Shape
{
    void * vptr;//Area and 
};
struct Circle
{
    int r;
};
struct Rectangle
{
    int l;
    int b;
};

int Circle_Area(Circle * const this)
{
    return (3.14*this->r * this->r);
}
int Rectangle_Area(Rectangle * const this)
{
    return (this->l * this->b);
})
int Area(void * sptr)
{
    if((Shape*)sptr->vptr  == &fptr_Circle[0])
    {
        Circle_Area(sptr);
    }
    else if((Shape*)sptr->vptr  == &fptr_Rectangle[0])
    {
        Rectangle_Area(sptr);
    }
}
int Circle_Perimeter(Circle * const this)
{
    return (2*3.14*this->r) ;
}
int Rectangle_Perimeter(Rectangle * const this)
{
    return (2*(this->l + this->b)) ;
}
int Perimeter(void * sptr)
{
    if((Shape*)sptr->vptr  == &fptr_Circle[0])
    {
        Circle_Perimeter(sptr);
    }
    else if((Shape*)sptr->vptr  == &fptr_Rectangle[0])
    {
        Rectangle_Perimeter(sptr);
    }
}
void InitializeVTable()
{
    fptr_Circle[0]=Circle_Area;
    fptr_Circle[1]=Circle_Perimeter;

    fptr_Rectangle[0] = Rectangle_Area;
    fptr_Rectangle[1] = Rectangle_Perimeter;
}
int main()
{
    InitializeVTable();
    Circle c;
    c.vprt=&fptr_Circle[0];
    Area(&c);
    return 0;
}
