void terrain_init(void);

struct Terrain
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
}; struct Terrain terrain[30];