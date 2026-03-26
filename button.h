#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <string>
#include <graphics.h>
#include <vector>
//#pragma once
//#include <string>
//#include <vector>
#include <map>
#include <queue>
#include <set>
#include <utility>  // 为了使用 std::pair
struct Station {
    std::string name;
    int line;

    // 添加构造函数
    Station() : name(""), line(0) {}  // 默认构造函数
    Station(const std::string& n, int l) : name(n), line(l) {}  // 带参数的构造函数
};
// 在 Button.h 中添加
struct RouteStep {
    std::string station;
    int line; // 当前站点的线路
};


struct MetroStation {
    int line;      // 所在线路
    std::string name;  // 站点名称
    std::vector<std::string> neighbors;  // 相邻站点
};
struct Path {
    std::vector<std::string> stations;
    std::vector<int> lines;
    int transfers;
};

struct StationInfo
{
    int index;//在站点数组中的索引
    std::vector<int> nextIndex;//能够到达的下一个站点的索引
};

class Button
{
private:
    int x; // 按钮左上角x坐标
    int y; // 按钮左上角y坐标
    int width; // 按钮宽度
    int height; // 按钮高度
    float scale; // 缩放比例，用于实现鼠标悬停效果
    bool isMouseOver; // 表示鼠标是否在按钮上方
    std::string text; // 按钮文本
    std::function<void(Button* btn)> onClick; // 点击按钮触发的函数

public:
    Button(int x, int y, int width, int height, const std::string& text, const std::function<void(Button* btn)>& onClick);

    // 检查鼠标是否在按钮上方
    void checkMouseOver(int mouseX, int mouseY);

    // 检查鼠标点击是否在按钮内，并执行函数
    bool checkClick(int mouseX, int mouseY);

  
    // 绘制按钮
    void draw();

    void setText(const std::string& newText);
    std::string getText() const {return text;}
};

class Widget
{
private:
    int width; // 宽度
    int height; // 高度
    //int ifound;
    int currentIndex; // 当前页面索引
    //char str[100][100];
    //int currentStartStationPage = 0;  // 当前始发站页码
    //const int stationsPerPage = 15;   // 每页显示的站点数量
    std::vector<IMAGE*> pages; // 存储所有页面的图片指针
    std::vector<std::vector<Button*>> buttons; // 存储每个页面上的按钮
    std::string startStation;
    std::string endStation;
    const std::string stationName;
    std::vector<std::string> startStations;
    std::vector<std::string> endStations;
   // bool isStationDataInitialized = false;  // 添加这个标志

    //新增
    std::map<std::string, Station> stationMap;  // 新增
    void initializeStationMap();                // 新增
    //Path findPath(const std::string& start, const std::string& end);  // 新增
    //void displayPath(const Path& path);         // 新增
    std::map<std::string, MetroStation> metroMap;  // 新增地铁网络图
    std::vector<int> findStationLines(const std::string& stationName);

    //int findStationLine(const std::string& stationName);  // 新增
    void calculateAndDisplayRoute(const std::string& start, const std::string& end);  // 新增

    void initStartStationPage();
    void initEndStationPage();
    void initTicketCountPage();

    //设置页面
    void setPage(int index,IMAGE* page); 

    // 添加一个页面
    void addPage(IMAGE* page);

    // 在指定页面上添加一个按钮
    void addButton(int index, Button* button);

    // 设置当前显示的页面索引
    int setCurrentIndex(int index);

    // 处理鼠标点击事件
    void mouseClick(int mouseX, int mouseY);

    // 处理鼠标移动事件
    void mouseMove(int mouseX, int mouseY);
    //void search(int ifound,char str[100][100]);
    // 绘制当前页面的内容
    void draw();

    //创建第一个欢迎界面
    IMAGE* CreateWelcomePage();
    // 创建第二个页面 主界面
    IMAGE* CreateStartHomePage();
    // 创建第三个页面 买票页面
    IMAGE* CreateTicketPage();
    // 创建第四个页面 查询地图页面
    IMAGE* CreateMapPage();
    //计算票价
    int calculateTicketPrice(std::vector<RouteStep> route, int ticketType);

public:
    Widget(int width, int height);
    ~Widget();
    // 初始化控件，创建图形环境，设置页面和按钮
    void init();

    // 运行，进入消息循环
    void run();

    // 关闭
    void close();

    void displayStationInfo(const std::string& startStation, const std::string& endStation);

    void initStationInfoPage();
    std::vector<RouteStep> findBestRoute(const std::string& start, const std::string& end);
    int findStationLine(const std::string& stationName); // 查找站点所属线路的函数声明
    std::vector<int> findStationIndexes(const std::string& stationName);// 查找站点中的索引
    std::vector<StationInfo> getStationInfo();//获取每个站点的信息
    std::vector<RouteStep> findShortestRoute(const std::string& start, const std::string& end);

    std::vector<StationInfo> stationInfo;

};
#endif // BUTTON_H

