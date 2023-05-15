
//Original values were made for this scale
#define ORGINAL_SCALE 0.89
//New radio size
#define NEW_SCALE 1.25

#define SCALE (NEW_SCALE/ORGINAL_SCALE)

#define BUTTON_W     0.024
#define BUTTON_H    0.02
#define BUTTONSIZE w = QUOTE(SCALE*BUTTON_W*safeZoneH); h = QUOTE(SCALE*BUTTON_H*safeZoneH)

#define BUTTON_X    0.443
#define BUTTON_Y    0.506

#define BUTTON_OFFX     0.0045
#define BUTTON_OFFY     0.0075

#define BUTTON_GRID(BX,BY)  x = QUOTE(((((BUTTON_X - 0.5)*SCALE)+0.5) * safeZoneH) + (((BUTTON_OFFX*safeZoneH* SCALE) + (BUTTON_W*safeZoneH* SCALE)) * BX) + safeZoneY);\
                            y = QUOTE(((((BUTTON_Y - 0.5)*SCALE)+0.5) * safeZoneH) + (((BUTTON_OFFY*safeZoneH* SCALE) + (BUTTON_H*safeZoneH* SCALE)) * BY) + safeZoneY)

#define CONTROL_SetRelativePos(xpos,ypos) x = QUOTE(H_OFFSET + (xpos * 0.001)); y = QUOTE(H_OFFSET + (ypos * 0.001));
#define CONTROL_SetDimensions(width, height) w = QUOTE(width * 0.001); h = QUOTE(height * 0.001);

#define BEGIN_CONTROL(name, parent, idval) class name: parent { idc = idval;
#define END_CONTROL        };

#define ROW_SMALL_X            0.436
#define ROW_SMALL_Y         0.415
#define ROW_SMALL_W         0.0038
#define ROW_SMALL_H         0.00805
#define ROW_SMALL_OFFX         0.0038
#define ROW_SMALL_OFFY         0.0083
#define ROW_SMALL_FONT_SIZE 0.01

#define ROW_LARGE_X            0.436
#define ROW_LARGE_Y         0.415
#define ROW_LARGE_W         0.0057
#define ROW_LARGE_H         0.01105
#define ROW_LARGE_OFFX         0.0057
#define ROW_LARGE_OFFY         0.011
#define ROW_LARGE_FONT_SIZE 0.015

#define ROW_XLARGE_X        0.436
#define ROW_XLARGE_Y         0.415
#define ROW_XLARGE_W         0.0070
#define ROW_XLARGE_H         0.020
#define ROW_XLARGE_OFFX         0.0070
#define ROW_XLARGE_OFFY         0.020
#define ROW_XLARGE_FONT_SIZE 0.020

#define ROW_XXLARGE_X            0.436
#define ROW_XXLARGE_Y         0.415
#define ROW_XXLARGE_W         0.0070
#define ROW_XXLARGE_H         0.020
#define ROW_XXLARGE_OFFX         0.0057
#define ROW_XXLARGE_OFFY         0.030
#define ROW_XXLARGE_FONT_SIZE 0.030

#define COMBINE(x,y) x##y

//colorBackground[] = {44/255,49/255,41/255,0};
#define TEXT_ROW_ELEMENT(CONTROL_ID,WIDTH,HEIGHT,TEXT_X,TEXT_OFFSETX,OFFSET_NUMX,TEXT_Y,TEXT_OFFSETY,OFFSET_NUMY,FONT_SIZE)\
    BEGIN_CONTROL(CONTROL_ID, Prc152_RscText, CONTROL_ID)\
        x = QUOTE(((((TEXT_X - 0.5)*SCALE)+0.5)* safeZoneH ) + ((TEXT_OFFSETX*safeZoneH * SCALE) * OFFSET_NUMX) + (safeZoneY));\
        y = QUOTE(((((TEXT_Y - 0.5)*SCALE)+0.5)* safeZoneH ) + ((TEXT_OFFSETY*safeZoneH * SCALE) * OFFSET_NUMY) + (safeZoneY));\
        w = QUOTE(SCALE*WIDTH*safeZoneH);\
        h = QUOTE(SCALE*HEIGHT*safeZoneH);\
        colorText[] = {0.2, 0.2, 0.2, 1};\
        colorBackground[] = {1,1,1,1};\
        sizeEx = QUOTE(SCALE*FONT_SIZE*safeZoneH);\
        text = "";\
    END_CONTROL

#define TEXT_ROW_SMALL(ROW_ID, ROW_X, ROW_Y, ROW_NUMBER, ROW_W, ROW_H, ROW_OFFSETX, ROW_OFFSETY, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,001), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 0, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,002), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 1, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,003), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 2, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,004), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 3, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,005), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 4, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,006), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 5, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,007), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 6, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,008), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 7, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,009), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 8, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,010), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 9, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,011), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 10, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,012), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 11, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,013), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 12, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,014), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 13, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,015), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 14, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,016), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 15, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,017), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 16, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,018), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 17, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,019), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 18, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,020), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 19, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,021), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 20, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,022), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 21, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,023), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 22, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,024), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 23, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,025), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 24, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,026), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 25, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,027), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 26, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,028), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 27, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,029), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 28, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,030), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 29, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,031), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 30, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,032), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 31, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,033), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 32, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)

#define TEXT_ROW_LARGE(ROW_ID, ROW_X, ROW_Y, ROW_NUMBER, ROW_W, ROW_H, ROW_OFFSETX, ROW_OFFSETY, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,001), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 0, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,002), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 1, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,003), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 2, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,004), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 3, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,005), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 4, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,006), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 5, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,007), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 6, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,008), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 7, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,009), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 8, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,010), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 9, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,011), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 10, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,012), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 11, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,013), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 12, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,014), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 13, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,015), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 14, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,016), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 15, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,017), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 16, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,018), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 17, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,019), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 18, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,020), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 19, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,021), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 20, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)

#define TEXT_ROW_XLARGE(ROW_ID, ROW_X, ROW_Y, ROW_NUMBER, ROW_W, ROW_H, ROW_OFFSETX, ROW_OFFSETY, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,001), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 0, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,002), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 1, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,003), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 2, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,004), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 3, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,005), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 4, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,006), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 5, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,007), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 6, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,008), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 7, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,009), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 8, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,010), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 9, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,011), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 10, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,012), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 11, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,013), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 12, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,014), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 13, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,015), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 14, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)

#define TEXT_ROW_XXLARGE(ROW_ID, ROW_X, ROW_Y, ROW_NUMBER, ROW_W, ROW_H, ROW_OFFSETX, ROW_OFFSETY, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,001), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 0, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,002), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 1, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,003), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 2, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,004), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 3, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,005), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 4, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,006), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 5, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,007), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 6, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,008), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 7, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,009), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 8, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,010), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 9, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,011), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 10, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)\
    TEXT_ROW_ELEMENT(COMBINE(ROW_ID,012), ROW_W, ROW_H, ROW_X, ROW_OFFSETX, 11, ROW_Y, ROW_OFFSETY, ROW_NUMBER, FONT_SIZE)

#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW 10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_XKEYDESC 40
#define CT_XBUTTON 41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_USER 99
#define CT_MAP 100
#define CT_MAP_MAIN 101 // Static styles

#define ST_POS 0x0F
#define ST_HPOS 0x03
#define ST_VPOS 0x0C
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0c
#define ST_TYPE 0xF0
#define ST_SINGLE 0
#define ST_MULTI 16
#define ST_TITLE_BAR 32
#define ST_PICTURE 48
#define ST_FRAME 64
#define ST_BACKGROUND 80
#define ST_GROUP_BOX 96
#define ST_GROUP_BOX2 112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE 144
#define ST_WITH_RECT 160
#define ST_LINE 176
#define ST_SHADOW 0x100
#define ST_NO_RECT 0x200
#define ST_KEEP_ASPECT_RATIO 0x800
#define ST_TITLE ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR 0x400
#define SL_VERT 0
#define SL_HORZ 0x400
#define SL_TEXTURES 0x10

// Listbox styles
#define LB_TEXTURES 0x10
#define LB_MULTI 0x20

#define FontM "TahomaB"
