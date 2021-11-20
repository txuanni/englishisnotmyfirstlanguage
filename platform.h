void platform_init(void);
void spawn_platform(void);


typedef struct Platform
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}Platform;

Platform platforms[30];


