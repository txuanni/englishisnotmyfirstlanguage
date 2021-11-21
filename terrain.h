void terrain_init(void);
void spawn_terrain(void);

struct Terrain
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}; struct Terrain terrain[30];