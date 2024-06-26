#ifndef AD_TYPES_H
#define AD_TYPES_H
enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT
};

enum LongitudinalAction
{
    LONGITUDINAL_ACTION_NONE,
    LONGITUDINAL_ACTION_INCREASE = 'w',
    LONGITUDINAL_ACTION_DECREASE = 's'
};

enum LateralAction
{
    LATERAL_ACTION_NONE,
    LATERAL_ACTION_LEFT = 'a',
    LATERAL_ACTION_RIGHT = 'd'
};

#endif
