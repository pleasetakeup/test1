
#define LV_COLOR_SET_R(c, v) (c).ch.red = (uint8_t)(((uint8_t)(v)) & 0x1F)
#define LV_COLOR_SET_G(c, v) (c).ch.green = (uint8_t)((v) & 0x3F)
#define LV_COLOR_SET_B(c, v) (c).ch.blue = (uint8_t)((v) & 0x1F)
#define LV_COLOR_SET_A(c, v)  do {} while(0)

#define LV_COLOR_GET_R(c) (c).ch.red
#define LV_COLOR_GET_G(c) (c).ch.green
#define LV_COLOR_GET_B(c) (c).ch.blue
#define LV_COLOR_GET_A(c)     0xFF

#define LV_CIRC_OCT1_X(p) (p.x)
#define LV_CIRC_OCT1_Y(p) (p.y)
#define LV_CIRC_OCT2_X(p) (p.y)
#define LV_CIRC_OCT2_Y(p) (p.x)
#define LV_CIRC_OCT3_X(p) (-p.y)
#define LV_CIRC_OCT3_Y(p) (p.x)
#define LV_CIRC_OCT4_X(p) (-p.x)
#define LV_CIRC_OCT4_Y(p) (p.y)
#define LV_CIRC_OCT5_X(p) (-p.x)
#define LV_CIRC_OCT5_Y(p) (-p.y)
#define LV_CIRC_OCT6_X(p) (-p.y)
#define LV_CIRC_OCT6_Y(p) (-p.x)
#define LV_CIRC_OCT7_X(p) (p.y)
#define LV_CIRC_OCT7_Y(p) (-p.x)
#define LV_CIRC_OCT8_X(p) (p.x)
#define LV_CIRC_OCT8_Y(p) (-p.y)
typedef struct
{
    int16_t x;
    int16_t y;
} lv_point_t;

typedef struct
{
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
} lv_area_t;

typedef union
{
    struct
    {
        uint16_t blue : 5;
        uint16_t green : 6;
        uint16_t red : 5;
    } ch;
    uint16_t full;
} lv_color_t;

static inline lv_color_t lv_color_mix(lv_color_t c1, lv_color_t c2, uint8_t mix)
{
    lv_color_t ret;
    /*LV_COLOR_DEPTH == 8, 16 or 32*/
    LV_COLOR_SET_R(ret, (uint16_t)((uint16_t) LV_COLOR_GET_R(c1) * mix + LV_COLOR_GET_R(c2) * (255 - mix)) >> 8);
    LV_COLOR_SET_G(ret, (uint16_t)((uint16_t) LV_COLOR_GET_G(c1) * mix + LV_COLOR_GET_G(c2) * (255 - mix)) >> 8);
    LV_COLOR_SET_B(ret, (uint16_t)((uint16_t) LV_COLOR_GET_B(c1) * mix + LV_COLOR_GET_B(c2) * (255 - mix)) >> 8);
    LV_COLOR_SET_A(ret, 0xFF);
    return ret;
    
}

// void drawRect_mid(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2){

       
        // uint16_t posy = 0;  
        // for(uint16_t row = y1+radius; row <= y2-radius; row++) {
            // posy  =  row ;
            // uint16_t mix          = (uint32_t)((uint32_t)(y2 - posy) * 255) / (100);
             // act_color    = lv_color_mix(mcolor, gcolor, mix);
 
            // tft.fillRect(x1,posy,x2-x1,1,act_color.full);
            
        // } 
 // }



