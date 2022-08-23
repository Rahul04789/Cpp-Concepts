
int (*fptr_Shape[2])(int);
int (*fptr_Circle[2])(int);
int (*fptr_Rectangle[2])(int);
struct Shape
{
    void * vptr;//Area and 
    void * obj;
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

int Circle_Area(struct Circle * const this)
{
    return (3.14*this->r * this->r);
}
int Rectangle_Area(struct Rectangle * const this)
{
    return (this->l * this->b);
}
int Area(struct Shape * sptr)
{
    if(sptr->vptr  == &fptr_Circle[0])
    {
        Circle_Area((struct Circle*)(sptr->obj));
    }
    else if(sptr->vptr  == &fptr_Rectangle[0])
    {
        Rectangle_Area((struct Rectangle*)(sptr->obj));
    }
}
int Circle_Perimeter(struct Circle * const this)
{
    return (2*3.14*this->r) ;
}
int Rectangle_Perimeter(struct Rectangle * const this)
{
    return (2*(this->l + this->b)) ;
}
int Perimeter(struct Shape * sptr)
{
    if(sptr->vptr  == &fptr_Circle[0])
    {
        Circle_Perimeter((struct Circle*)(sptr->obj));
    }
    else if(sptr->vptr  == &fptr_Rectangle[0])
    {
        Rectangle_Perimeter((struct Rectangle*)(sptr->obj));
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
    struct Shape s;
    struct Circle c;c.r=10;
    s.vptr=&fptr_Circle[0];
    s.obj=(void*)&c;
    Area(&s);
    return 0;
}
