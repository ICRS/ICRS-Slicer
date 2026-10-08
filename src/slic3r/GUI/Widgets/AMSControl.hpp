#ifndef slic3r_GUI_AMXCONTROL_hpp_
#define slic3r_GUI_AMXCONTROL_hpp_

#include "../wxExtensions.hpp"
#include "StaticBox.hpp"
#include "StepCtrl.hpp"
#include "Button.hpp"
#include "AMSItem.hpp"
#include "../DeviceManager.hpp"
#include "slic3r/GUI/Event.hpp"
#include "slic3r/GUI/AmsMappingPopup.hpp"
#include <wx/simplebook.h>
#include <wx/hyperlink.h>
#include <wx/animate.h>
#include <wx/dynarray.h>

<<<<<<< HEAD
#define AMS_CONTROL_BRAND_COLOUR wxColour(0, 133, 255)
#define AMS_CONTROL_GRAY700 wxColour(107, 107, 107)
#define AMS_CONTROL_GRAY800 wxColour(50, 58, 61)
#define AMS_CONTROL_GRAY500 wxColour(172, 172, 172)
#define AMS_CONTROL_DISABLE_COLOUR wxColour(206, 206, 206)
#define AMS_CONTROL_DISABLE_TEXT_COLOUR wxColour(144, 144, 144)
#define AMS_CONTROL_WHITE_COLOUR wxColour(255, 255, 255)
#define AMS_CONTROL_BLACK_COLOUR wxColour(0, 0, 0)
#define AMS_CONTROL_DEF_BLOCK_BK_COLOUR wxColour(238, 238, 238)
#define AMS_CONTROL_DEF_LIB_BK_COLOUR wxColour(248, 248, 248)
#define AMS_EXTRUDER_DEF_COLOUR wxColour(234, 234, 234)
#define AMS_CONTROL_MAX_COUNT 4
#define AMS_CONTRO_CALIBRATION_BUTTON_SIZE wxSize(FromDIP(150), FromDIP(28))
=======
#include "slic3r/GUI/DeviceCore/DevExtruderSystem.h"
>>>>>>> 8500fcdccaa10b5099ac20d252af3a7c560046f1


namespace Slic3r { namespace GUI {

<<<<<<< HEAD
enum AMSModel {
    NO_AMS              = 0,
    GENERIC_AMS         = 1,
    EXTRA_AMS           = 2
};

enum ActionButton {
    ACTION_BTN_CALI     = 0,
    ACTION_BTN_LOAD     = 1,
    ACTION_BTN_UNLOAD   = 2,
    ACTION_BTN_COUNT    = 3
};

enum class AMSRoadMode : int {
    AMS_ROAD_MODE_LEFT,
    AMS_ROAD_MODE_LEFT_RIGHT,
    AMS_ROAD_MODE_END,
    AMS_ROAD_MODE_END_ONLY,
    AMS_ROAD_MODE_NONE,
    AMS_ROAD_MODE_NONE_ANY_ROAD,
    AMS_ROAD_MODE_VIRTUAL_TRAY
};

enum class AMSPassRoadMode : int {
    AMS_ROAD_MODE_NONE,
    AMS_ROAD_MODE_LEFT,
    AMS_ROAD_MODE_LEFT_RIGHT,
    AMS_ROAD_MODE_END_TOP,
    AMS_ROAD_MODE_END_RIGHT,
    AMS_ROAD_MODE_END_BOTTOM,
};

enum class AMSAction : int {
    AMS_ACTION_NONE,
    AMS_ACTION_LOAD,
    AMS_ACTION_UNLOAD,
    AMS_ACTION_CALI,
    AMS_ACTION_PRINTING,
    AMS_ACTION_NORMAL,
    AMS_ACTION_NOAMS,
};

enum class AMSPassRoadSTEP : int {
    AMS_ROAD_STEP_NONE,
    AMS_ROAD_STEP_1, // lib -> extrusion
    AMS_ROAD_STEP_2, // extrusion->buffer
    AMS_ROAD_STEP_3, // extrusion

    AMS_ROAD_STEP_COMBO_LOAD_STEP1,
    AMS_ROAD_STEP_COMBO_LOAD_STEP2,
    AMS_ROAD_STEP_COMBO_LOAD_STEP3,
};

enum class AMSPassRoadType : int {
    AMS_ROAD_TYPE_NONE,
    AMS_ROAD_TYPE_LOAD,
    AMS_ROAD_TYPE_UNLOAD,
};

enum class AMSCanType : int {
    AMS_CAN_TYPE_NONE,
    AMS_CAN_TYPE_BRAND,
    AMS_CAN_TYPE_THIRDBRAND,
    AMS_CAN_TYPE_EMPTY,
    AMS_CAN_TYPE_VIRTUAL,
};

enum FilamentStep {
    STEP_IDLE,
    STEP_HEAT_NOZZLE,
    STEP_CUT_FILAMENT,
    STEP_PULL_CURR_FILAMENT,
    STEP_PUSH_NEW_FILAMENT,
    STEP_PURGE_OLD_FILAMENT,
    STEP_FEED_FILAMENT,
    STEP_CONFIRM_EXTRUDED,
    STEP_CHECK_POSITION,
    STEP_COUNT,
};

enum FilamentStepType {
    STEP_TYPE_LOAD      = 0,
    STEP_TYPE_UNLOAD    = 1,
    STEP_TYPE_VT_LOAD   = 2,
};

#define AMS_ITEM_CUBE_SIZE wxSize(FromDIP(14), FromDIP(14))
#define AMS_ITEM_SIZE wxSize(FromDIP(82), FromDIP(27))
#define AMS_ITEM_HUMIDITY_SIZE wxSize(FromDIP(120), FromDIP(27))
#define AMS_CAN_LIB_SIZE wxSize(FromDIP(58), FromDIP(80))
#define AMS_CAN_ROAD_SIZE wxSize(FromDIP(66), FromDIP(70))
#define AMS_CAN_ITEM_HEIGHT_SIZE FromDIP(27)
#define AMS_CANS_SIZE wxSize(FromDIP(284), FromDIP(196))
#define AMS_CANS_WINDOW_SIZE wxSize(FromDIP(264), FromDIP(196))
#define AMS_STEP_SIZE wxSize(FromDIP(172), FromDIP(196))
#define AMS_REFRESH_SIZE wxSize(FromDIP(30), FromDIP(30))
#define AMS_EXTRUDER_SIZE wxSize(FromDIP(86), FromDIP(72))
#define AMS_EXTRUDER_BITMAP_SIZE wxSize(FromDIP(36), FromDIP(55))

struct Caninfo
{
    std::string     can_id;
    wxString        material_name;
    wxColour        material_colour = {*wxWHITE};
    AMSCanType      material_state;
    int             ctype=0;
    int             material_remain = 100;
    float           k = 0.0f;
    float           n = 0.0f;
    std::vector<wxColour> material_cols;
};

struct AMSinfo
{
public:
    std::string             ams_id;
    std::vector<Caninfo>    cans;
    std::string             current_can_id;
    AMSPassRoadSTEP         current_step;
    AMSAction               current_action;
    int                     curreent_filamentstep;
    int                     ams_humidity = 0;

    bool parse_ams_info(MachineObject* obj, Ams *ams, bool remain_flag = false, bool humidity_flag = false);
};

/*************************************************
Description:AMSrefresh
**************************************************/
#define AMS_REFRESH_PLAY_LOADING_TIMER 100
class AMSrefresh : public wxWindow
{
public:
    AMSrefresh();
    AMSrefresh(wxWindow *parent, wxString number, Caninfo info, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    AMSrefresh(wxWindow *parent, int number, Caninfo info, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    ~AMSrefresh();
    void    PlayLoading();
    void    StopLoading();
    void    create(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    void    on_timer(wxTimerEvent &event);
    void    OnEnterWindow(wxMouseEvent &evt);
    void    OnLeaveWindow(wxMouseEvent &evt);
    void    OnClick(wxMouseEvent &evt);
    void    post_event(wxCommandEvent &&event);
    void    paintEvent(wxPaintEvent &evt);
    void    Update(std::string ams_id, Caninfo info);
    void    msw_rescale();
    void    set_disable_mode(bool disable) { m_disable_mode = disable; }
    Caninfo m_info;


protected:
    wxTimer *m_playing_timer= {nullptr};
    int      m_rotation_angle = 0;
    bool             m_play_loading = {false};
    bool             m_selected      = {false};

    std::string      m_ams_id;
    std::string      m_can_id;

    ScalableBitmap   m_bitmap_normal;
    ScalableBitmap   m_bitmap_selected;
    ScalableBitmap   m_bitmap_ams_rfid_0;
    ScalableBitmap   m_bitmap_ams_rfid_1;
    ScalableBitmap   m_bitmap_ams_rfid_2;
    ScalableBitmap   m_bitmap_ams_rfid_3;
    ScalableBitmap   m_bitmap_ams_rfid_4;
    ScalableBitmap   m_bitmap_ams_rfid_5;
    ScalableBitmap   m_bitmap_ams_rfid_6;
    ScalableBitmap   m_bitmap_ams_rfid_7;
    std::vector<ScalableBitmap> m_rfid_bitmap_list;

    wxString         m_refresh_id;
    wxBoxSizer *     m_size_body;
    virtual void     DoSetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO);

    bool m_disable_mode{ false };
};

/*************************************************
Description:AMSextruder
**************************************************/
class AMSextruderImage: public wxWindow
{
public:
    void TurnOn(wxColour col);
    void TurnOff();
    void msw_rescale();
    void paintEvent(wxPaintEvent &evt);

	void            render(wxDC &dc);
    bool            m_turn_on = {false};
    wxColour        m_colour;
    ScalableBitmap  m_ams_extruder;
    void            doRender(wxDC &dc);
    AMSextruderImage(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    ~AMSextruderImage();
};


class AMSextruder : public wxWindow
{
public:
    void TurnOn(wxColour col);
    void TurnOff();
    void create(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    void OnVamsLoading(bool load, wxColour col = AMS_CONTROL_GRAY500);
    void OnAmsLoading(bool load, wxColour col = AMS_CONTROL_GRAY500);
    void paintEvent(wxPaintEvent& evt);
    void render(wxDC& dc);
    void doRender(wxDC& dc);
    void msw_rescale();
    void has_ams(bool hams) {m_has_vams = hams; Refresh();};
    void no_ams_mode(bool mode) {m_none_ams_mode = mode; Refresh();};

    bool            m_none_ams_mode{true};
    bool            m_has_vams{false};
    bool            m_vams_loading{false};
    bool            m_ams_loading{false};
    wxColour        m_current_colur;

    wxBoxSizer *    m_bitmap_sizer{nullptr};
    wxPanel *       m_bitmap_panel{nullptr};
    AMSextruderImage *m_amsSextruder{nullptr};
    ScalableBitmap        monitor_ams_extruder;
    AMSextruder(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    ~AMSextruder();
};

class AMSVirtualRoad : public wxWindow
{
public:
    AMSVirtualRoad(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    ~AMSVirtualRoad();

private:
    bool    m_has_vams{ true };
    bool    m_vams_loading{ false };
    wxColour m_current_color;

public:
    void OnVamsLoading(bool load, wxColour col = AMS_CONTROL_GRAY500);
    void SetHasVams(bool hvams) { m_has_vams = hvams; };
    void create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    void paintEvent(wxPaintEvent& evt);
    void render(wxDC& dc);
    void doRender(wxDC& dc);
    void msw_rescale();
};

/*************************************************
Description:AMSLib
**************************************************/
class AMSLib : public wxWindow
{
public:
    AMSLib(wxWindow *parent, Caninfo info);
    void create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
public:
    wxColour     GetLibColour();
    Caninfo      m_info;
    MachineObject* m_obj = {nullptr};
    int          m_can_index = 0;
    AMSModel     m_ams_model;

    void         Update(Caninfo info, bool refresh = true);
    void         UnableSelected() { m_unable_selected = true; };
    void         EableSelected() { m_unable_selected = false; };
    void         OnSelected();
    void         UnSelected();
    bool         is_selected() {return m_selected;};
    void         post_event(wxCommandEvent &&event);
    void         show_kn_value(bool show) { m_show_kn = show; };
    void         support_cali(bool sup) { m_support_cali = sup; Refresh(); };
    virtual bool Enable(bool enable = true);
    void         set_disable_mode(bool disable) { m_disable_mode = disable; }
    void         msw_rescale();
    void         on_pass_road(bool pass);

protected:
    wxStaticBitmap *m_edit_bitmp       = {nullptr};
    wxStaticBitmap *m_edit_bitmp_light = {nullptr};
    ScalableBitmap  m_bitmap_editable;
    ScalableBitmap  m_bitmap_editable_light;
    ScalableBitmap  m_bitmap_readonly;
    ScalableBitmap  m_bitmap_readonly_light;
    ScalableBitmap  m_bitmap_transparent;

    ScalableBitmap  m_bitmap_extra_tray_left;
    ScalableBitmap  m_bitmap_extra_tray_right;

    ScalableBitmap  m_bitmap_extra_tray_left_hover;
    ScalableBitmap  m_bitmap_extra_tray_right_hover;

    ScalableBitmap  m_bitmap_extra_tray_left_selected;
    ScalableBitmap  m_bitmap_extra_tray_right_selected;

    bool            m_unable_selected = {false};
    bool            m_enable          = {false};
    bool            m_selected        = {false};
    bool            m_hover           = {false};
    bool            m_show_kn         = {false};
    bool            m_support_cali    = {false};
    bool            transparent_changed     = {false};

    double   m_radius = {4};
    wxColour m_border_color;
    wxColour m_road_def_color;
    wxColour m_lib_color;
    bool m_disable_mode{ false };
    bool m_pass_road{false};

    void on_enter_window(wxMouseEvent &evt);
    void on_leave_window(wxMouseEvent &evt);
    void on_left_down(wxMouseEvent &evt);
    void paintEvent(wxPaintEvent &evt);
    void render(wxDC &dc);
    void render_extra_text(wxDC& dc);
    void render_generic_text(wxDC& dc);
    void doRender(wxDC& dc);
    void render_extra_lib(wxDC& dc);
    void render_generic_lib(wxDC& dc);
};

/*************************************************
Description:AMSRoad
**************************************************/
class AMSRoad : public wxWindow
{
public:
    AMSRoad();
    AMSRoad(wxWindow *parent, wxWindowID id, Caninfo info, int canindex, int maxcan, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    void create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);

public:
    AMSinfo                      m_amsinfo;
    Caninfo                      m_info;
    int                          m_canindex       = {0};
    AMSRoadMode                  m_rode_mode      = {AMSRoadMode::AMS_ROAD_MODE_LEFT_RIGHT};
    std::vector<AMSPassRoadMode> m_pass_rode_mode = {AMSPassRoadMode::AMS_ROAD_MODE_NONE};
    bool                         m_selected       = {false};
    int                          m_passroad_width = {6};
    double                       m_radius         = {4};
    wxColour                     m_road_def_color;
    wxColour                     m_road_color;
    void                         Update(AMSinfo amsinfo, Caninfo info, int canindex, int maxcan);

    std::vector<ScalableBitmap> ams_humidity_img;


    int      m_humidity = { 0 };
    bool     m_show_humidity = { false };
    bool     m_vams_loading{false};
    AMSModel m_ams_model;

    void OnVamsLoading(bool load, wxColour col = AMS_CONTROL_GRAY500);
    void SetPassRoadColour(wxColour col);
    void SetMode(AMSRoadMode mode);
    void OnPassRoad(std::vector<AMSPassRoadMode> prord_list);
    void UpdatePassRoad(int tag_index, AMSPassRoadType type, AMSPassRoadSTEP step);

    void paintEvent(wxPaintEvent &evt);
    void render(wxDC &dc);
    void doRender(wxDC &dc);
};

/*************************************************
Description:AMSItem
**************************************************/

class AMSItem : public wxWindow
{
public:
    AMSItem();
    AMSItem(wxWindow *parent, wxWindowID id, AMSinfo amsinfo, const wxSize cube_size = wxSize(14, 14), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);

    bool m_open = {false};
    void Open();
    void Close();

    void         Update(AMSinfo amsinfo);
    void         create(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    void         OnEnterWindow(wxMouseEvent &evt);
    void         OnLeaveWindow(wxMouseEvent &evt);
    void         OnSelected();
    void         UnSelected();
    virtual bool Enable(bool enable = true);

    AMSinfo      m_amsinfo;

protected:
    wxSize   m_cube_size;
    wxColour m_background_colour = {AMS_CONTROL_DEF_BLOCK_BK_COLOUR};
    int      m_padding           = {7};
    int      m_space             = {5};
    bool     m_hover             = {false};
    bool     m_selected          = {false};
    ScalableBitmap* m_ts_bitmap_cube;

    void         paintEvent(wxPaintEvent &evt);
    void         render(wxDC &dc);
    void         doRender(wxDC &dc);
    virtual void DoSetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO);
};

/*************************************************
Description:AmsCans
**************************************************/
class Canrefreshs
{
public:
    wxString    canID;
    AMSrefresh *canrefresh;
};

class CanLibs
{
public:
    wxString canID;
    AMSLib * canLib;
};

class CanRoads
{
public:
    wxString canID;
    AMSRoad *canRoad;
};

WX_DEFINE_ARRAY(Canrefreshs *, CanrefreshsHash);
WX_DEFINE_ARRAY(CanLibs *, CanLibsHash);
WX_DEFINE_ARRAY(CanRoads *, CansRoadsHash);

class AmsCans : public wxWindow
{
public:
    AmsCans();
    AmsCans(wxWindow *parent, AMSinfo info, AMSModel model);

    void     Update(AMSinfo info);
    void     create(wxWindow *parent);
    void     AddCan(Caninfo caninfo, int canindex, int maxcan, wxBoxSizer* sizer);
    void     SetDefSelectCan();
    void     SelectCan(std::string canid);
    void     PlayRridLoading(wxString canid);
    void     StopRridLoading(wxString canid);
    void     msw_rescale();
    void     show_sn_value(bool show);
    void     SetAmsStepExtra(wxString canid, AMSPassRoadType type, AMSPassRoadSTEP step);
    void     SetAmsStep(wxString canid, AMSPassRoadType type, AMSPassRoadSTEP step);
    void     SetAmsStep(std::string can_id);
    void     paintEvent(wxPaintEvent& evt);
    void     render(wxDC& dc);
    void     doRender(wxDC& dc);
    wxColour GetTagColr(wxString canid);
    std::string GetCurrentCan();

public:
    ScalableBitmap  m_bitmap_extra_framework;
    int             m_canlib_selection = { -1 };
    int             m_selection = { 0 };
    int             m_can_count = { 0 };
    AMSModel        m_ams_model;
    std::string     m_canlib_id;

    std::string     m_road_canid;
    wxColour        m_road_colour;

    CanLibsHash     m_can_lib_list;
    CansRoadsHash   m_can_road_list;
    CanrefreshsHash m_can_refresh_list;
    AMSinfo         m_info;
    wxBoxSizer *    sizer_can = {nullptr};
    wxBoxSizer *    sizer_can_middle = {nullptr};
    wxBoxSizer *    sizer_can_left = {nullptr};
    wxBoxSizer *    sizer_can_right = {nullptr};
    AMSPassRoadSTEP m_step    = {AMSPassRoadSTEP ::AMS_ROAD_STEP_NONE};
};

/*************************************************
Description:AMSControl
**************************************************/
class AmsCansWindow
{
public:
    wxString amsIndex;
    AmsCans *amsCans;
    bool m_disable_mode{ false };

    void set_disable_mode(bool disable) {
        m_disable_mode = disable;
        for (auto can_lib : amsCans->m_can_lib_list) {
            can_lib->canLib->set_disable_mode(disable);
        }
        for (auto can_refresh : amsCans->m_can_refresh_list) {
            can_refresh->canrefresh->set_disable_mode(disable);
        }
    }
};

class AmsItems
{
public:
    wxString amsIndex;
    AMSItem *amsItem;
};

class AMSextruders
{
public:
    wxString     amsIndex;
    AMSextruder *amsextruder;
};

WX_DEFINE_ARRAY(AmsCansWindow *, AmsCansHash);
WX_DEFINE_ARRAY(AmsItems *, AmsItemsHash);
WX_DEFINE_ARRAY(AMSextruders *, AMSextrudersHash);
=======
//Previous definitions
class uiAmsPercentHumidityDryPopup;
>>>>>>> 8500fcdccaa10b5099ac20d252af3a7c560046f1

class AMSControl : public wxSimplebook
{
public:
    AMSControl(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
    ~AMSControl();

    void on_retry();

protected:
    std::string  m_current_ams;
    std::string  m_current_slot_left;
    std::string  m_current_slot_right;
    std::string  m_current_show_ams_left;
    std::string  m_current_show_ams_right;
    std::map<std::string, int> m_ams_selection;

<<<<<<< HEAD
    AmsItemsHash m_ams_item_list;
=======
    std::map<std::string, AMSPreview*> m_ams_preview_list;
>>>>>>> 8500fcdccaa10b5099ac20d252af3a7c560046f1

    std::vector<AMSinfo>       m_ams_info;
    std::vector<AMSinfo>       m_ext_info;
    std::map<std::string, AmsItem*>  m_ams_item_list;
    std::map<std::string, AMSExtImage*> m_ext_image_list;

    std::string                      m_dev_id;
    std::vector<std::vector<std::string>> m_item_ids{ {}, {} };
    std::vector<std::pair<string, string>> pair_id;

    int         m_total_ext_count = 1;
    AMSextruder *m_extruder{nullptr};
    AMSRoadDownPart* m_down_road{ nullptr };

    /*items*/
    wxBoxSizer* m_sizer_ams_items{nullptr};
    wxScrolledWindow* m_panel_prv_left {nullptr};
    wxScrolledWindow* m_panel_prv_right{nullptr};
    wxBoxSizer* m_sizer_prv_left{nullptr};
    wxBoxSizer* m_sizer_prv_right{nullptr};

    /*ams */
    wxBoxSizer *m_sizer_ams_body{nullptr};
    wxBoxSizer* m_sizer_ams_area_left{nullptr};
    wxBoxSizer* m_sizer_ams_area_right{nullptr};
    wxBoxSizer* m_sizer_down_road{ nullptr };

    /*option*/
    wxBoxSizer *m_sizer_ams_option{nullptr};
    wxBoxSizer* m_sizer_option_left{nullptr};
    wxBoxSizer* m_sizer_option_mid{nullptr};
    wxBoxSizer* m_sizer_option_right{nullptr};


    AmsIntroducePopup m_ams_introduce_popup;

    //wxSimplebook *m_simplebook_right{nullptr};
    wxSimplebook *m_simplebook_ams_left{nullptr};
    wxSimplebook *m_simplebook_ams_right{ nullptr };
    wxSimplebook *m_simplebook_bottom{nullptr};
    wxPanel      *m_panel_down_road{ nullptr };
    int          m_left_page_index = 0;
    int          m_right_page_index = 0;


    wxStaticText *m_tip_right_top{nullptr};
    Label        *m_tip_load_info{nullptr};
    wxWindow *    m_amswin{nullptr};
    wxBoxSizer*   m_vams_sizer{nullptr};
    wxBoxSizer*   m_sizer_vams_tips{nullptr};

<<<<<<< HEAD
    wxStaticText *m_tip_right_top            = {nullptr};
    Label        *m_tip_load_info            = {nullptr};
    wxStaticText *m_text_calibration_percent = {nullptr};
    wxWindow *    m_none_ams_panel           = {nullptr};
    wxWindow *    m_panel_top                = {nullptr};
    wxWindow *    m_amswin                   = {nullptr};
    wxBoxSizer*   m_vams_sizer               = {nullptr};
    wxBoxSizer*   m_sizer_vams_tips          = {nullptr};

    Label*          m_ams_backup_tip = {nullptr};
    Label*          m_ams_tip       = {nullptr};
=======
    Label*          m_ams_tip       {nullptr};
>>>>>>> 8500fcdccaa10b5099ac20d252af3a7c560046f1

    Caninfo         m_vams_info;
    StaticBox*      m_panel_virtual {nullptr};
    AMSLib*         m_vams_lib      {nullptr};
    AMSRoad*        m_vams_road     {nullptr};


    wxBoxSizer *m_sizer_right_tip {nullptr};
    wxBoxSizer* m_sizer_ams_tips  {nullptr};

    ::StepIndicator *m_filament_load_step   {nullptr};
    ::StepIndicator *m_filament_unload_step {nullptr};
    ::StepIndicator *m_filament_vt_load_step {nullptr};

    Button *m_button_extruder_feed {nullptr};
    Button *m_button_extruder_back {nullptr};
    Button *m_button_auto_refill{ nullptr };
    wxStaticBitmap* m_button_ams_setting   {nullptr};
    wxStaticBitmap* m_img_ams_backup  {nullptr};
    wxStaticBitmap* m_img_amsmapping_tip {nullptr};
    wxStaticBitmap* m_img_vams_tip {nullptr};
    ScalableBitmap m_button_ams_setting_normal;
    ScalableBitmap m_button_ams_setting_hover;
    ScalableBitmap m_button_ams_setting_press;

    AmsHumidityTipPopup m_Humidity_tip_popup;
    uiAmsPercentHumidityDryPopup* m_percent_humidity_dry_popup;

    std::string m_last_ams_id = "";
    std::string m_last_tray_id = "";

public:
    std::string GetCurentAms();
    std::string GetCurentShowAms(AMSPanelPos pos = AMSPanelPos::RIGHT_PANEL);
    std::string GetCurrentCan(std::string amsid);
    bool        IsAmsInRightPanel(std::string ams_id);
	wxColour GetCanColour(std::string amsid, std::string canid);
    void createAms(wxSimplebook* parent, int& idx, AMSinfo info, AMSPanelPos pos);
    void createAmsPanel(wxSimplebook *parent, int &idx, std::vector<AMSinfo> infos, const std::string &series_name, const std::string &printer_type, AMSPanelPos pos, int total_ext_num);
    AMSRoadShowMode findFirstMode(AMSPanelPos pos);

    AMSModel m_ams_model{AMSModel::EXT_AMS};
    AMSModel m_ext_model{AMSModel::EXT_AMS};
    AMSModel m_is_none_ams_mode{AMSModel::EXT_AMS};
    bool     m_single_nozzle_no_ams = { true };

    void SetAmsModel(AMSModel mode, AMSModel ext_mode) {m_ams_model = mode; m_ext_model = ext_mode;};
    void AmsSelectedSwitch(wxCommandEvent& event);

    void EnableLoadFilamentBtn(bool enable, const std::string& ams_id, const std::string& can_id, const wxString& tips);
    void EnableUnLoadFilamentBtn(bool enable, const std::string& ams_id, const std::string& can_id,const wxString& tips);

    void EnterNoneAMSMode();
    void EnterGenericAMSMode();
    void EnterExtraAMSMode();

    void PlayRridLoading(wxString amsid, wxString canid);
    void StopRridLoading(wxString amsid, wxString canid);
    void ShowFilamentTip(bool hasams = true);

    void UpdatePassRoad(string ams_id, AMSPassRoadType type, AMSPassRoadSTEP step);
    void CreateAms();
    void CreateAmsDoubleNozzle(const std::string &series_name, const std::string& printer_type);
    void CreateAmsSingleNozzle(const std::string &series_name, const std::string &printer_type);
    void ClearAms();
    void UpdateAms(const std::string   &series_name,
                   const std::string   &printer_type,
                   std::vector<AMSinfo> ams_info,
                   std::vector<AMSinfo> ext_info,
                   DevExtderSystem           data,
                   std::string          dev_id,
                   bool                 is_reset = true,
                   bool                 test     = false);
    std::vector<AMSinfo> GenerateSimulateData();

    void AddAms(AMSinfo info, AMSPanelPos pos = AMSPanelPos::LEFT_PANEL);
    //void AddExtAms(int ams_id);
    void AddAmsPreview(AMSinfo info, AMSModel type);
    //void AddExtraAms(AMSinfo info);

    void AddAms(std::vector<AMSinfo> single_info, const std::string &series_name, const std::string &printer_type, AMSPanelPos pos = AMSPanelPos::LEFT_PANEL);
    void AddAmsPreview(std::vector<AMSinfo>single_info, AMSPanelPos pos);
    //void AddExtraAms(std::vector<AMSinfo>single_info);
    void SetExtruder(bool on_off, int nozzle_id, std::string ams_id, std::string slot_id);
    void SetAmsStep(std::string ams_id, std::string canid, AMSPassRoadType type, AMSPassRoadSTEP step);
    void SwitchAms(std::string ams_id);

    void msw_rescale();
    void on_filament_load(wxCommandEvent &event);
    void on_filament_unload(wxCommandEvent &event);
    void auto_refill(wxCommandEvent& event);
    void on_ams_setting_click(wxMouseEvent &event);
    void on_extrusion_cali(wxCommandEvent &event);
    void on_ams_setting_click(wxCommandEvent &event);
    void on_clibration_again_click(wxMouseEvent &event);
    void on_clibration_cancel_click(wxMouseEvent &event);
    void Reset();

    void show_noams_mode();
    void show_auto_refill(bool show);
    void enable_ams_setting(bool en);
    void show_vams_kn_value(bool show);
    void post_event(wxEvent&& event);

    virtual bool Enable(bool enable = true);
    void parse_object(MachineObject* obj);

private:
    std::string get_filament_id(const std::string& ams_id, const std::string& can_id);

public:
    std::string m_current_select;
};

}} // namespace Slic3r::GUI

#endif // !slic3r_GUI_amscontrol_hpp_
