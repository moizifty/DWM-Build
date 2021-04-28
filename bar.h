typedef enum ElementType
{
    BE_STATUS,
    BE_ALL_TAGS,
    BE_CURR_TAGS,
    BE_ALL_LAYOUT,
    BE_CURR_LAYOUT,
    BE_TITLE,
    BE_SEP,
    BE_END,
}ElementType;

typedef enum VPos
{
    VPOS_TOP,
    VPOS_MIDDLE,
    VPOS_BOTTOM, 
}VPos;

typedef enum HPos
{
    HPOS_RIGHT,
    HPOS_MIDDLE,
    HPOS_LEFT,
}HPos;

typedef enum Width
{
    WIDTH_FILL = 6969,
}Width;
typedef struct IndicatorPos
{
    HPos hPos;
    VPos vPos;
    int posXOffset, posYOffset; //offset from 'pos'
}IndicatorPos;

typedef struct BarElement
{
    Bool invertFGBG;
    ElementType elemType;
    Bool showIndicator;
    IndicatorPos indicatorPos;
    int indicatorWidth;
    unsigned int indicatorFillWidthOffset;
    int indicatorHeight;

    int iData[6];
    char strData[24];
}BarElement;

static const BarElement barElems[] = 
{
    {
        .showIndicator = True,
        .indicatorPos = {.hPos = HPOS_MIDDLE, .vPos = VPOS_TOP, .posYOffset = -1},
        .indicatorWidth = WIDTH_FILL,
        .indicatorFillWidthOffset = 8,
        .indicatorHeight = 3,
        .elemType = BE_CURR_TAGS, 
        .iData = {1, 0}
    },
    {
        .elemType = BE_SEP, 
        .strData = "::"
    },
    {
        .elemType = BE_ALL_LAYOUT, 
        .iData = {1}
    },
    {
        .indicatorPos = {.hPos = HPOS_MIDDLE, .vPos = VPOS_TOP, .posYOffset = -1},
        .indicatorWidth = 0,
        .indicatorFillWidthOffset = 0,
        .indicatorHeight = 3,
        .elemType = BE_TITLE
    },
    {
        .indicatorPos = {.hPos = HPOS_MIDDLE, .vPos = VPOS_TOP, .posYOffset = -1},
        .indicatorWidth = 0,
        .indicatorFillWidthOffset = 0,
        .indicatorHeight = 3,
        .elemType = BE_STATUS
    },
    {
        .elemType = BE_END
    },
};
