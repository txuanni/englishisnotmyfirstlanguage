void platform_init(void);
void spawn_platform(void);


struct Platform
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}; struct Platform platforms[30];




