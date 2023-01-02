/*
    MPOS_Grid: A module of the mpos library usind the SDL library to provide 
               basic grid and isometric grid handling.
    License:   zlib license
*/
#ifndef __MPOS_GRID_H__
#define __MPOS_GRID_H__

#include <SDL2/SDL.h>


/* MPOS_Vector2: represents a point */

typedef struct
{
    int32_t x;
    int32_t y;
} MPOS_Vector2;


/* MPOS_Matrix: represents a matrix */

typedef struct
{
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t d;
} MPOS_Matrix;


/* MPOS_GridTile: structure for single tile information  */

typedef struct
{
    u_int32_t key;          /* key in grid tile array */
    u_int32_t row;          /* row number in grid */
    u_int32_t col;          /* col number in grid */
    SDL_Rect rect;          /* position (x, y) and size (w, h) */
} MPOS_GridTile;


/* MPOS_GridTileNeighbors: structure for tile neighbors */

typedef struct
{
    u_int32_t l;            /* key of left neighbor */
    u_int32_t r;            /* key of right neighbor */
    u_int32_t t;            /* key of top neighbor */
    u_int32_t b;            /* key of bottom neighbor */
    u_int32_t tl;           /* key of top left neighbor */
    u_int32_t tr;           /* key of top right neighbor */
    u_int32_t bl;           /* key of bottom left neighbor */
    u_int32_t br;           /* key of bottom right neighbor */
} MPOS_GridTileNeighbors;


/* MPOS_Grid: structure for all grid information */

typedef struct
{
    SDL_Rect rect;          /* position (x, y), cols (w) and rows (h) */
    u_int32_t t_w;          /* single tile with */
    u_int32_t t_h;          /* single tile height */
    SDL_Color c;            /* grid drawing color */
    u_int32_t t_c;          /* tile count in tile array */
    MPOS_GridTile tiles[];  /* array of all tiles in grid */
} MPOS_Grid;


/**
 * Creates a MPOS_Grid.
 *
 * \param rect an SDL_Rect structure representing position and vector size
 * \param t_w an u_int32_t representing the tile width
 * \param t_h an u_int32_t representing the tile height
 * \returns an MPOS_Grid pointer to the calculated grid
 *
 * \since This function is available since MPOS 1.0.0.
 */
MPOS_Grid * MPOS_CreateGrid(SDL_Rect rect, u_int32_t t_w, u_int32_t t_h);

/* calculates all tiles of given grid */

/**
 * Calculates all tiles.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 *
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_CalcGrid(MPOS_Grid *grid);

/**
 * Sets line color for grid drawing.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param color an u_int32_t rgb color value
 *
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_SetGridColor(MPOS_Grid *grid, u_int32_t color);

/**
 * Draws a grid.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param renderer an SDL_Renderer pointer to draw on
 *
 * \sa MPOS_DrawGrid
 * \sa MPOS_DrawIsoGrid
 * 
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_DrawGrid(MPOS_Grid *grid, SDL_Renderer *renderer);

/**
 * Moves every tile in a grid.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param x an int32_t value with pixel for x-axis
 * \param y an int32_t value with pixel for y-axis
 *
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_MoveGrid(MPOS_Grid *grid, int32_t x, int32_t y);

/* returns tiles array key in given grid by given position */

/**
 * Calculates tile key by position.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param x an int32_t representing pixel on x-axis
 * \param y an int32_t representing pixel on y-axis
 * \returns tile key on success, or -1 on error
 *
 * \since This function is available since MPOS 1.0.0.
 */
int32_t MPOS_GetTileKeyByPos(MPOS_Grid *grid, int32_t x, int32_t y);

/**
 * Creates a MPOS_Grid for isometric grid in the inner of an rectangle.
 * 
 * \param rect an SDL_Rect structure representing position and vector size
 * \param t_w an u_int32_t representing the tile width
 * \param t_h an u_int32_t representing the tile height
 * \returns an MPOS_Grid pointer to the calculated grid
 * 
 * \attention is not compatible with all isometric functions
 * 
 * \sa MPOS_CalcIsoGrid
 * \sa MPOS_DrawIsoGrid
 * \sa MPOS_GetIsoTileKeyByPos
 * \sa MPOS_GetIsoTileNeighborsByKey
 * 
 * \since This function is available since MPOS 1.0.0.
 */
MPOS_Grid * MPOS_CreateIsoGrid(SDL_Rect rect, u_int32_t t_w , u_int32_t t_h);

/**
 * Calculates all tiles of an isometric grid.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateIsoGrid
 * 
 * \sa MPOS_CreateIsoGrid
 * \sa MPOS_DrawIsoGrid
 * \sa MPOS_GetIsoTileKeyByPos
 * \sa MPOS_GetIsoTileNeighborsByKey
 *
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_CalcIsoGrid(MPOS_Grid *grid);

/**
 * Draws an isometric grid.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateIsoGrid
 * \param renderer an SDL_Renderer pointer to draw on
 *
 * \sa MPOS_CreateIsoGrid
 * \sa MPOS_CalcIsoGrid
 * \sa MPOS_GetIsoTileKeyByPos
 * \sa MPOS_GetIsoTileNeighborsByKey
 * 
 * \since This function is available since MPOS 1.0.0.
 */
void MPOS_DrawIsoGrid(MPOS_Grid *grid, SDL_Renderer *renderer);

/* returns tiles array key in given isometric grid by given position */

/**
 * Calculates isometric tile key by position.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateIsoGrid
 * \param x an int32_t representing pixel on x-axis
 * \param y an int32_t representing pixel on y-axis
 * \returns tile key on success, or -1 on error
 *
 * \sa MPOS_CreateIsoGrid
 * \sa MPOS_CalcIsoGrid
 * \sa MPOS_DrawIsoGrid
 * \sa MPOS_GetIsoTileNeighborsByKey
 * 
 * \since This function is available since MPOS 1.0.0.
 */
int32_t MPOS_GetIsoTileKeyByPos(MPOS_Grid *grid, int32_t x, int32_t y);

/**
 * Calculates the area of a triangle.
 *
 * \param x1 an float point x value of first point
 * \param y1 an float point y value of first point
 * \param x2 an float point x value of second point
 * \param y2 an float point y value of second point
 * \param x3 an float point x value of third point
 * \param y3 an float point y value of third point
 * \returns an float as the area
 * 
 * \since This function is available since MPOS 1.0.0.
 */
float MPOS_CalcTriangleArea(float x1, float y1, float x2, float y2, 
                            float x3, float y3);

/**
 * Checks if a point is in a triangle.
 *
 * \param x1 an float point x value of triangles first point
 * \param y1 an float point y value of triangles first point
 * \param x2 an float point x value of triangles second point
 * \param y2 an float point y value of triangles second point
 * \param x3 an float point x value of triangles third point
 * \param y3 an float point y value of triangles third point
 * \param x an float point x value of point to be checked
 * \param y an float point y value of of point to be checked
 * \returns 1 on success, or 0 on error
 * 
 * \since This function is available since MPOS 1.0.0.
 */
uint8_t MPOS_IsPointInTriangle(float x1, float y1, float x2, float y2, 
                               float x3, float y3, float x, float y);

/**
 * Calculates isometric tile neighbors.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateIsoGrid
 * \param key an u_int32_t representing the key of the tile to be checked
 * \returns an MPOS_GridTileNeighbors structure
 *
 * \sa MPOS_CreateIsoGrid
 * \sa MPOS_CalcIsoGrid
 * \sa MPOS_DrawIsoGrid
 * \sa MPOS_GetIsoTileKeyByPos
 * 
 * \since This function is available since MPOS 1.0.0.
 */
MPOS_GridTileNeighbors MPOS_GetIsoTileNeighborsByKey(MPOS_Grid *grid, 
                                                     u_int32_t key);

/**
 * Calculates tiles isometric grid vector from grid vector.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param vec an MPOS_Vector2 structure representing the tile vector
 * \returns an MPOS_Vector2 with the calculated isometric vector
 *
 * \since This function is available since MPOS 1.0.0.
 *
 * \sa MPOS_GetTileIsoGridPos
 * \sa MPOS_GetTileGridVector
 * \sa MPOS_GetTileGridPos
 */
MPOS_Vector2 MPOS_GetTileIsoGridVector(MPOS_Grid *grid, MPOS_Vector2 vec);

/**
 * Calculates tiles isometric grid position from grid position.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param x an int32_t representing the isometric x-value of the tile
 * \param y an int32_t representing the isometric y-value of the tile
 * \returns an MPOS_Vector2 with the calculated position
 *
 * \since This function is available since MPOS 1.0.0.
 *
 * \sa MPOS_GetTileIsoGridVector
 * \sa MPOS_GetTileGridVector
 * \sa MPOS_GetTileGridPos
 */
MPOS_Vector2 MPOS_GetTileIsoGridPos(MPOS_Grid *grid, int32_t x, int32_t y);

/* inverts given matrix */
/**
 * Inverts a matrix.
 *
 * \param matrix an MPOS_Matrix structure
 * \returns an MPOS_Matrix structure
 *
 * \since This function is available since MPOS 1.0.0.
 */
MPOS_Matrix MPOS_InvertMatrix(MPOS_Matrix matrix);

/**
 * Calculates tiles grid vector from isometric vector.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param vec an MPOS_Vector2 structure representing the isometric tile vector
 * \returns an MPOS_Vector2 with the calculated vector
 *
 * \since This function is available since MPOS 1.0.0.
 *
 * \sa MPOS_GetTileIsoGridVector
 * \sa MPOS_GetTileGridPos
 * \sa MPOS_GetTileIsoGridPos
 */
MPOS_Vector2 MPOS_GetTileGridVector(MPOS_Grid *grid, MPOS_Vector2 vec);

/**
 * Calculates tiles grid position from isometric grid position.
 *
 * \param grid an MPOS_Grid pointer created with MPOS_CreateGrid
 * \param x an int32_t representing the x-value of the tile
 * \param y an int32_t representing the y-value of the tile
 * \returns an MPOS_Vector2 with the calculated position
 *
 * \since This function is available since MPOS 1.0.0.
 *
 * \sa MPOS_GetTileIsoGridVector
 * \sa MPOS_GetTileGridVector
 * \sa MPOS_GetTileIsoGridPos
 */
MPOS_Vector2 MPOS_GetTileGridPos(MPOS_Grid *grid, int32_t x, int32_t y);

#endif /* !__MPOS_GRID_H__ */
