#include "Button.h"
#include <graphics.h>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <imm.h>
#include <queue>
#include <set>
#include <map>
#pragma comment(lib, "imm32.lib")


#define PAGE_INDEX_WECOME 0  //欢迎界面下标
#define PAGE_INDEX_HOME   1  //主页面下标
#define PAGE_INDEX_TICKET 2  //票购买界面下标
#define PAGE_INDEX_MAP    3  //查询地图界面下标

//using namespace std;  // 在文件开头添加
struct name_matrix
{
    int line;
    const char name[30];
    const char ENGname[100];
};
struct name_matrix station[] = {
    { 1,"机场东","Airport_East" },
    {1,"后瑞","Hourui" },
    {1,"固戍","Gushu"},
    {1,"西乡","Xixiang"},
     {1,"坪洲","Pingzhou"},
     {1,"宝体","Baoan_Stadium"},
     {1,"宝安中心","Baoan_Center"},
     {1,"新安","Xinan"},
     {1,"前海湾","Qianhaiwan"},
     {1,"鲤鱼门","Liyumen"},
     {1,"大新","Daxin"},
     {1,"桃园","Taoyuan"},
     {1,"深大","Shenzhen_University"},
     {1,"高新园","Hi_Tech_Park"},
     {1,"白石洲","Baishizhou"},
     {1,"世界之窗","Window_of_the_World"},
     {1,"华侨城","OCT"},
     {1,"侨城东","Qiaocheng_East"},
     {1,"竹子林","Zhuzilin"},
     {1,"车公庙","Chegongmiao"},
     {1,"香蜜湖","Xiangmihu"},
     {1,"购物公园","Shopping_Park"},
     {1,"会展中心","Conversation_Exhibition_Center"},
     {1,"岗厦","Gangxia"},
     {1,"华强路","Huaqiang_Road"},
     {1,"科学馆","Science_Museum"},
     {1,"大剧院","Grand_Center"},
     {1,"老街","Laojie"},
     {1,"国贸","Guomao"},
     {1,"罗湖","Luohu"} ,
     {2, "赤湾","Chiwan" },
     {2,"蛇口港","Shekou_Port"},
     {2,"海上世界","Sea_World"},
     {2,"水湾","Shuiwan"},
     {2,"东角头","Dongjiaotou"},
     {2,"湾厦","Wanxia"},
     {2,"海月","Haiyue"},
     {2,"登良","Dengliang"},
     {2,"后海","Houhai"},
     {2,"科苑","Keyuan"},
     {2,"红树湾","Hongshuwan"},
     {2,"世界之窗","Window_of_the_World"},
     {2,"侨城北","Qiaocheng_North"},
     {2,"深康","Shenkang"},
     {2,"安托山","Antuo_Hill"},
     {2,"侨香","Qiaoxiang"},
     {2,"香蜜","Xiangmi"},
     {2,"香梅北","Xiangmei_North"},
     {2,"景田","Jingtian"},
     {2,"莲花西","Lianhua_West"},
     {2,"福田","Futian"},
     {2,"市民中心","Civic_Center"},
     {2,"岗厦北","Gangxia_North"},
     {2,"华强北","Huaqiang_North"},
     {2,"燕南","Yannan"},
     {2,"大剧院","Grand_Center"},
     {2,"湖贝","Hubei"},
     {2,"黄贝岭","Huangbeiling"},
     {2,"新秀","Xinxiu"},
     {2,"莲塘口岸","Liantang_Checkpoint"},
     {2,"仙湖路","Xianhulu"},
     {2,"莲塘","Liantang"},
     {3,"福保","Futian_Bonded_Area" },
     {3,"益田","Yitian"},
     {3,"石厦","Shixia"},
     {3,"购物公园","Shopping_Park"},
     {3,"福田","Futian"},
     {3,"少年宫","Children_s_Palace"},
     {3,"莲花村","Lianhuacun"},
     {3,"华新","Huaxin"},
     {3,"通新岭","Tongxinling"},
     {3,"红岭","Hongling"},
     {3,"老街","Laojie"},
     {3,"晒布","Shaibu"},
     {3,"翠竹","Cuizhu"},
     {3,"田贝","Tianbei"},
     {3,"水贝","Shuibei"},
     {3,"草埔","Caopu"},
     {3,"布吉","Buji"},
     {3,"木棉湾","Mumianwan"},
     {3,"大芬","Dafen"},
     {3,"丹竹头","Danzhutou"},
     {3,"六约","Liuyue"},
     {3,"塘坑","Tangkeng"},
     {3,"横岗","Henggang"},
     {3,"永湖","Yonghu"},
     {3,"荷坳","Heao"},
     {3,"大运","Universiade"},
     {3,"爱联","Ailian"},
     {3,"吉祥","Jixiang"},
     {3,"龙城广场","LongCheng_Square"},
     {3,"南联","Nanlian"},
     {3,"双龙","Shuanglong"} ,
     {4,"牛湖","Niuhu"},
     {4,"观澜湖","Guanlanhu"},
     {4,"松原厦","Songyuanxia"},
     {4,"观澜","Guanlan"},
     {4,"长湖","Changhu"},
     {4,"茜坑","Xikeng"},
     {4,"竹村","Zhucun"},
     {4,"清湖北","Qinghu_North"},
     {4,"清湖","Qinghu"},
     {4,"龙华","Longhua"},
     {4,"龙胜","Longsheng"},
     {4,"上塘","Shangtang"},
     {4,"红山","Hongshan"},
     {4,"深圳北站","Shenzhen_North_Station"},
     {4,"白石龙","Baishilong"},
     {4,"民乐","Minle"},
     {4,"上梅林","Shangmeilin"},
     {4,"莲花北","Lianhua_North"},
     {4,"少年宫","Children_s_Palace"},
     {4,"市民中心","Civic_Center"},
     {4,"会展中心","Conversation_Exhibition_Center"},
     {4,"福民","Fumin"},
     {4,"福田口岸","Futian_Checkpoint"},
     {5,"5号线","null" },
     {5, "赤湾","Chiwan" },
     {5, "荔湾","Liwan" },
     {5, "铁路公园","Railway_Park" },
     {5, "妈湾","Mawan" },
     {5, "前湾公园","Qianwan_Park" },
     {5, "前湾","Qianwan" },
     {5, "桂湾","Guiwan" },
     {5, "前海湾","Qianhaiwan" },
     {5, "临海","Linhai" },
     {5, "宝华","Baohua" },
     {5, "宝安中心","Baoan_Center" },
     {5, "翻身","Fanshen" },
     {5, "灵芝","Linzhi" },
     {5, "洪浪北","Honglang_North" },
     {5, "兴东","Xingdong" },
     {5, "留仙洞","Liuxiandong" },
     {5, "西丽","Xili" },
     {5, "大学城","University_Town" },
     {5, "塘朗","Tanglang" },
     {5, "长岭陂","Changlingpi" },
     {5, "深圳北站","Shenzhen_North_Station" },
     {5, "民治","Minzhi" },
     {5, "五和","Wuhe" },
     {5, "坂田","Bantian" },
     {5, "杨美","Yangmei" },
     {5, "上水径","Shangshuijin" },
     {5, "下水径","Xiashuijin" },
     {5, "长龙","Changlong" },
     {5, "布吉","Buji" },
     {5, "百鸽笼","Baigelong" },
     {5, "布心","Buxin" },
     {5, "太安","Taian" },
     {5, "怡景","Yijing" },
     { 5, "黄贝岭","Huangbeiling" } };
#define NUM_STATIONS sizeof(station)/sizeof(station[0])


Button::Button(int x, int y, int width, int height, const std::string& text, const std::function<void(Button* btn)>& onClick)
    : x(x), y(y), width(width), height(height), text(text), onClick(onClick), scale(1.0f), isMouseOver(false)
{
}

void Button::checkMouseOver(int mouseX, int mouseY)
{
    isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);

    if (isMouseOver) {
        scale = 0.9f; // 鼠标悬停时缩放按钮
    }
    else {
        scale = 1.0f; // 恢复按钮原始大小
    }
}

bool Button::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        onClick(this); // 执行按钮点击时的函数
        isMouseOver = false;
        scale = 1.0f;
        return true;
    }
    return false;
}

void Button::draw()
{
    int scaledWidth = width * scale; // 缩放后的按钮宽度
    int scaledHeight = height * scale; // 缩放后的按钮高度
    int scaledX = x + (width - scaledWidth) / 2; // 缩放后的按钮x坐标
    int scaledY = y + (height - scaledHeight) / 2; // 缩放后的按钮y坐标

    if (isMouseOver)
    {
        setlinecolor(RGB(0, 120, 215)); // 鼠标悬停时按钮边框颜色
        setfillcolor(RGB(229, 241, 251)); // 鼠标悬停时按钮填充颜色
    }
    else
    {
        setlinecolor(RGB(173, 173, 173)); // 按钮边框颜色
        setfillcolor(RGB(225, 225, 225)); // 按钮填充颜色
    }

    fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // 绘制按钮
    settextcolor(BLACK); // 设置文本颜色为黑色
    setbkmode(TRANSPARENT); // 设置文本背景透明
    settextstyle(20 * scale, 0, _T("微软雅黑")); // 设置文本大小和字体

    //居中显示按钮文本
    int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; // 计算文本在按钮中央的x坐标
    int textY = scaledY + (scaledHeight - textheight(_T("微软雅黑"))) / 2; // 计算文本在按钮中央的y坐标
    outtextxy(textX, textY, text.c_str()); // 在按钮上绘制文本
}

void Button::setText(const std::string& newText)
{
    text = newText;
}


Widget::Widget(int width, int height)
    : width(width), height(height), currentIndex(-1)
{
}

Widget::~Widget()
{
    for (auto page : pages) {
        delete page;
    }
    for (auto& btns : buttons) {
        for (auto button : btns) {
            delete button;
        }
    }
}

void Widget::addPage(IMAGE* page)
{
    pages.push_back(page);
    buttons.push_back({});
}

void Widget::addButton(int index, Button* button)
{
    if (index >= 0 && index < buttons.size())
    {
        buttons[index].push_back(button);
    }
}

void Widget::mouseClick(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button* button : buttons[currentIndex])
        {
            if (button->checkClick(mouseX, mouseY))
            {
                break;
            }
        }
    }
}

void Widget::mouseMove(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button* button : buttons[currentIndex])
        {
            button->checkMouseOver(mouseX, mouseY);
        }
    }
}
/**void Widget::search(int ifound, char str[100][100])
{
    for (int j = 1; j <= ifound; j++)
    {
        outtextxy(120, 100, "你查询的站点有以下线路");
        outtextxy(100 + j * 70, 150, str[j]);
        outtextxy(100 + j * 78, 150, "号线");
        outtextxy(120, 200, "请点击数字查询详细地铁线路图");
    }
    if (!ifound)
        outtextxy(120, 200, _T("您输入的站点不存在"));
}**/
void Widget::draw()
{
    if (currentIndex >= 0 && currentIndex < pages.size())
    {
        putimage(0, 0, pages[currentIndex]); // 在窗口中绘制当前页面的图片

        if (currentIndex >= 0 && currentIndex < buttons.size())
        {
            for (Button* button : buttons[currentIndex])
            {
                button->draw(); // 绘制当前页面上的所有按钮
            }
        }
    }
}

IMAGE* Widget::CreateWelcomePage()
{
    IMAGE* page = new IMAGE(width, height);
    SetWorkingImage(page);
    setbkcolor(RGB(240, 240, 240));
    cleardevice();//设置背景颜色
    //绘制文字
    settextstyle(80, 0, _T("微软雅黑"));
    RECT rect;
    rect.left = 0;
    rect.top = 20;
    rect.right = width;
    rect.bottom = rect.top + 100; // 设置文本高度
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    drawtext(_T("欢迎使用地铁售票系统"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    //填写系统说明区
    settextstyle(30, 0, _T("微软雅黑"));
    settextcolor(BLACK);
    rect.left = 20;
    rect.top = 200;
    rect.right = 500;
    rect.bottom = height;
    setfillcolor(WHITE);
    fillrectangle(rect.left, rect.top, rect.right, rect.bottom);
    drawtext(_T("（1）打开模拟地铁售票系统，可以用鼠标点击选择购买地铁票、查询站点、退出系统三个按钮。（2）若点击地图查询，会跳出提示框，用户可用键盘输入想要查询的站点的中文名称，点击确定后会进行跳转。跳转后可用鼠标点击所在的线路名称显示该线路的地图或者点击返回主界面。（3）若点击够买地铁票，会跳出始发站和终点站按钮，点击可分别输入输入完成后若始发站和终点站均存在，可点击按钮查看线路，点击后会显示最短线路；还可点击按钮购票，输入张数可自动计算票价，输入花的钱可计算找零。"), &rect, DT_LEFT| DT_WORDBREAK);

    //绘制作者信息
    settextstyle(50, 0, _T("微软雅黑"));
    settextcolor(LIGHTCYAN);
    outtextxy(550, 200, _T("作者：刘星语、赵远媛"));
    outtextxy(550, 300, _T("联系方式：19867109206"));
    outtextxy(550, 400, _T("版权所有：刘星语、赵远媛"));
   

    SetWorkingImage(NULL); //将页面设置回去

    setPage(PAGE_INDEX_WECOME, page);

    //添加一个确定按钮
    Button* button1 = new Button(550, 550, 200, 50, "确认", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_HOME); //进入到主界面
    });

    addButton(PAGE_INDEX_WECOME, button1);

    return page;
}

IMAGE* Widget::CreateStartHomePage()
{
    IMAGE* page = new IMAGE(width, height);
    SetWorkingImage(page);
    setbkcolor(RGB(240, 240, 240));
    cleardevice();//设置背景颜色
    //绘制文字
    settextstyle(80, 0, _T("微软雅黑"));
    RECT rect;
    rect.left = 0;
    rect.top = 20;
    rect.right = width;
    rect.bottom = rect.top + 100; // 设置文本高度
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    drawtext(_T("地铁售票系统主页"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    setPage(PAGE_INDEX_HOME, page);
    SetWorkingImage(NULL); //将页面设置回去

    //添加一个购票按钮
    Button* button1 = new Button((width - 200)/2, 350, 200, 50, "购买地铁票", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_TICKET);
    });
    addButton(PAGE_INDEX_HOME, button1);

    //添加一个查询站点按钮
    Button* button2 = new Button((width - 200) / 2, 450, 200, 50, "查询站点", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_MAP);
    });
    addButton(PAGE_INDEX_HOME, button2);

    //添加一个退出系统按钮
    Button* button3 = new Button((width - 200) / 2, 550, 200, 50, "退出系统", [&](Button* btn) {
        closegraph();
        exit(0);
    });
    addButton(PAGE_INDEX_HOME, button3);

    //添加一个查看购票须知按钮
    Button* button4 = new Button(50, 50, 100, 30, "查看购票须知", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_WECOME);//回到欢迎界面
    });
    addButton(PAGE_INDEX_HOME, button4);

    return page;
}

IMAGE* Widget::CreateTicketPage()
{
    IMAGE* page = new IMAGE(width, height);
    SetWorkingImage(page);
    //加载图片
    loadimage(page, "./MapResource/MetroMap.jpg", width, height - 50);
    setfillcolor(RGB(240, 240, 240));
    fillrectangle(0, height - 50, width, height);//设置背景颜色

    SetWorkingImage(NULL);

    setPage(PAGE_INDEX_TICKET, page);

    //添加一个输入始发站按钮
    Button* button1 = new Button(50, height - 40, 100, 30, "输入始发站", [&](Button* btn) {
        char station[100] = { 0 };
        InputBox(station, 100, "请输入始发站");
        if (station[0] == '\0')
        {
            return;
        }
        //查询始发站
        auto stationLines = findStationLines(station);
        if (stationLines.size() == 0) {
            MessageBox(GetHWnd(), _T("您输入的始发站不存在"), _T("提示"), MB_OK);
        }
        else {
            startStation = station;
            //将按钮名字改了
            buttons[PAGE_INDEX_TICKET][0]->setText(station);
        }
    });
    addButton(PAGE_INDEX_TICKET, button1);

    //添加一个输入终点站按钮
    Button* button2 = new Button(250, height - 40, 100, 30, "输入终点站", [&](Button* btn) {
        char station[100] = { 0 };
        InputBox(station, 100, "请输入终点站");
        if (station[0] == '\0')
        {
            return;
        }
        //查询终点站
        auto stationLines = findStationLines(station);
        if (stationLines.size() == 0) {
            MessageBox(GetHWnd(), _T("您输入的终点站不存在"), _T("提示"), MB_OK);
        }
        else {
            endStation = station;
            //将按钮名字改了
            buttons[PAGE_INDEX_TICKET][1]->setText(station);
        }
    });
    addButton(PAGE_INDEX_TICKET, button2);

    //添加一个购买按钮
    Button* button3 = new Button(450, height - 40, 100, 30, "购买", [&](Button* btn) {
        if (startStation.empty() || endStation.empty())
        {
            MessageBox(GetHWnd(), _T("请输入始发站和终点站"), _T("提示"), MB_OK);
            return;
        }
        //弹出需要买几张 输入
        char tickets[100] = { 0 };
        InputBox(tickets, 100, "需要买几张");
        int num = atoi(tickets);
        if (num <= 0) {
            MessageBox(GetHWnd(), _T("请输入正确的数量"), _T("提示"), MB_OK);
        }
        else {
            //计算需要花费的钱
            std::vector<RouteStep> route = findShortestRoute(startStation, endStation);
            if (route.size() == 0) {
                MessageBox(GetHWnd(), _T("没有找到合适的线路"), _T("提示"), MB_OK);
                return;
            }
            int price = calculateTicketPrice(route, 1);
            std::string str = "总共的票价是：" + std::to_string(price * num) +"元\n每张" +std::to_string(price) + "元* 购买" + std::to_string(num) + "张\n请输入花费金额";
            price *= num;
            //输入花费多少钱
            char cost[100] = { 0 };
            InputBox(cost, 100, str.c_str());
            int money = atoi(cost);
            if (money < price) {
                MessageBox(GetHWnd(), _T("您的钱不够"), _T("提示"), MB_OK);
                return;
            }
            int change = money - price;
            str = "购买成功\n找零：" + std::to_string(change) + "元";
            //购买
            MessageBox(GetHWnd(), str.c_str(), _T("提示"), MB_OK);
        }
    });
    addButton(PAGE_INDEX_TICKET, button3);

    //添加一个查看线路的按钮
    Button* button4 = new Button(650, height - 40, 100, 30, "查看线路", [&](Button* btn) {
        //始发站和终点站是否为空
        if (startStation.empty() || endStation.empty())
        {
            MessageBox(GetHWnd(), _T("请输入始发站和终点站"), _T("提示"), MB_OK);
            return;
        }
        
        std::vector<RouteStep> route = findShortestRoute(startStation, endStation);
        if (route.size() == 0) {
            MessageBox(GetHWnd(), _T("没有找到合适的线路"), _T("提示"), MB_OK);
            return;
        }
        std::string str = "乘坐线路：" + std::to_string(route[0].line) + "号线" + route[0].station;
        int line = route[0].line;
        for (int i = 1; i < route.size(); i++) {
            str += "->";
            if (route[i].line != line) {
                str += "换乘到" + std::to_string(route[i].line) + "号线";
                line = route[i].line;
            }
            str += route[i].station;
        }
        MessageBox(GetHWnd(), str.c_str(), _T("提示"), MB_OK);
    });
    addButton(PAGE_INDEX_TICKET, button4);
    Button* button5 = new Button(850, height - 40, 100, 30, "返回主界面", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_HOME);
        });
    addButton(PAGE_INDEX_TICKET, button5);
    return page;
}

IMAGE* Widget::CreateMapPage()
{
    IMAGE* page = new IMAGE(width, height);
    SetWorkingImage(page);
    setbkcolor(RGB(240, 240, 240));
    cleardevice();
    //绘制文字
    settextstyle(80, 0, _T("微软雅黑"));
    RECT rect;
    rect.left = 0;
    rect.top = 20;
    rect.right = width;
    rect.bottom = rect.top + 100; // 设置文本高度
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    drawtext(_T("站点查询"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    SetWorkingImage(NULL);

    setPage(PAGE_INDEX_MAP, page);


    //添加一个输入始发站按钮
    Button* button1 = new Button(50, height - 40, 100, 30, "输入站点", [&](Button* btn) {
        char station[100] = { 0 };
        InputBox(station, 100, "请输入站点");
        if (station[0] == '\0')
        {
            return;
        }
        //移除所有按钮
        for (int i = 1; i < buttons[PAGE_INDEX_MAP].size(); i++) {
            delete buttons[PAGE_INDEX_MAP][i];
        }
        buttons[PAGE_INDEX_MAP].resize(1);

        //查询始发站
        auto stationLines = findStationLines(station);
        if (stationLines.size() == 0)
        {
            MessageBox(GetHWnd(), _T("您输入的站点不存在"), _T("提示"), MB_OK);
            return;
        }
        for (int i = 0; i < stationLines.size(); i++) {
            //创建所有按钮 依次排列
            Button* button = new Button(50 + 150 * (i + 1), height - 40, 100, 30, "Line" + std::to_string(stationLines[i]), [&](Button* btn) {
                //将图片改为对应站点的
                IMAGE img;
                std::string  path = "./MapResource/"+btn->getText() + ".png";
                loadimage(&img, path.c_str(), width, height - 50);
                SetWorkingImage(pages[PAGE_INDEX_MAP]);
                putimage(0, 0, &img);
                SetWorkingImage(NULL);
                });
            addButton(PAGE_INDEX_MAP, button);
         
        }
        Button* button_3 = new Button(850, height - 40, 100, 30, "返回主界面", [&](Button* btn) {
            setCurrentIndex(PAGE_INDEX_HOME);
            });
        addButton(PAGE_INDEX_MAP, button_3);
        });
    addButton(PAGE_INDEX_MAP, button1);
    Button* button_2 = new Button(850, height - 40, 100, 30, "返回主界面", [&](Button* btn) {
        setCurrentIndex(PAGE_INDEX_HOME);
        });
    addButton(PAGE_INDEX_MAP, button_2);
    return page;

}

int Widget::calculateTicketPrice(std::vector<RouteStep> route, int ticketType)
{
    //目前计算票价只是简单根据站数计算 如果后续有更复杂的规则 可以再改
    //每3站加1元 最低2元
    int price = 2 + (route.size() - 1) / 3;

    return price;
}

void Widget::init()
{
    initgraph(width, height);

    CreateWelcomePage();
    CreateStartHomePage();
    CreateTicketPage();
    CreateMapPage();
    setCurrentIndex(PAGE_INDEX_WECOME);

#if 0


    // 创建页面1
    IMAGE* page1 = new IMAGE(width, height);
    setfillcolor(RGB(240, 240, 240)); // 设置页面1的背景颜色为浅灰色
    solidrectangle(0, 0, width, height); // 绘制页面1的背景矩形
    getimage(page1, 0, 0, width, height); // 将页面1的内容保存到图片中

    addPage(page1); // 添加页面1

    // 在页面1创建按钮1
    Button* button1_1 = new Button(720, 400, 200, 50, "欢迎使用地铁售票系统", [&]() {
        // 点击按钮1时，可以进行相关的操作，这里没有做具体操作。
        });
    addButton(0, button1_1); // 将按钮1添加到页面1
    Button* button1_3 = new Button(370, 510, 200, 50, "购买地铁票", [&]() {
        // 点击按钮1时，可以进行相关的操作，这里没有做具体操作。
        initStartStationPage(); // 初始化始发站页面
        initEndStationPage();   // 初始化终点站页面
        //initTicketCountPage();  // 初始化票数选择页面
        setCurrentIndex(2);     // 切换到始发站选择页面
        });
    addButton(0, button1_3); // 将按钮1添加到页面1
    // 在页面1创建按钮2
    Button* button1_2 = new Button(1060, 510, 200, 50, "查询地图", [&]() {
        // 点击按钮2时，执行查询操作
        char s[1000];
        char str[100][100];
        int ifound = 0;
        int line[10] = {0};
        // 获取用户输入
        InputBox(s, 1000, _T("请输入您要查询的站点"));

        // 假设 `station` 是一个已定义的数组，包含站点信息（如 name 和 line）
        for (int i = 0; i <= 303; i++)
        {
            if (strcmp(s, station[i].name) == 0)
            {
                ifound++;
                sprintf_s(str[ifound], "%d", station[i].line);
                strcat_s(str[ifound], "号线");
                line[ifound] = station[i].line;
            }
        }

        // 创建页面2
        IMAGE* page2 = new IMAGE(width, height);
        setfillcolor(WHITE); // 设置页面2的背景颜色为红色
        solidrectangle(0, 0, width, height); // 绘制页面2的背景矩
        // 注意：此时不能立即调用 getimage，因为此时页面2并未完成绘制
        // 我们在绘制查询结果后再保存页面内容

        // 绘制查询结果
        if (ifound > 0)
        {
            settextstyle(30, 10,"楷体");
            outtextxy(720, 100, "你查询的站点有以下线路:");
           
            outtextxy(700, 250, "请点击数字查询详细地铁线路图");
        }
        else
        {
            outtextxy(700, 200, _T("您输入的站点不存在"));
        }

        // 将页面2的内容保存到图片中
        getimage(page2, 0, 0, width, height); // 将页面2的内容保存到图片中
      
        addPage(page2); // 添加页面2
        //cleardevice();
        // 设置页面切换为页面2
        setCurrentIndex(1);
        //int last_j = 0;
        // 在页面2创建返回按钮
        for (int j = 1; j <= ifound; j++)
        {
            //outtextxy(100 + j * 70, 150, str[j]);
            //outtextxy(100 + j * 78, 150, "号线");
            Button* button2_j = new Button(600 + j * 120, 150, 100, 30, str[j], [&,j,line]() {
                
                //printf_s("k=%d", k);
                    setCurrentIndex(2); // 点击按钮1时，切换回页面3
                    // cleardevice();
                    std::cout << "Switching to page j" << std::endl;
                    IMAGE* page3 = new IMAGE(width, height);
                    setfillcolor(WHITE); // 设置页面3的背景颜色为白色
                    solidrectangle(0, 0, width, height); // 绘制页面3的背景

                    // 通过线路编号加载图片，假设图片的文件名为“lineX.png”，其中X是线路号
                    char imagePath[1000];

                    int result = snprintf(imagePath, sizeof(imagePath), "D:\\TicketingSystem\\TicketingSystem\\MapResource\\Line%d.png", line[j]);
                    printf_s("line[%d]=%d", j, line[j]);
                    if (result < 0) {
                        std::cerr << "Error formatting the string, result: " << result << std::endl;
                    }
                    else {
                        std::cout << "Formatted path: " << imagePath << std::endl;
                    }
                    // 检查是否成功格式化
                    // 加载线路图片并显示
                   //cleardevice();
                    //while (last_j != j)
                    //{
                        loadimage(page3, imagePath, width, height); // 加载并显示对应线路的图片
                        // 获取图片的原始宽高
                        int imgWidth = (*page3).getwidth();
                        int imgHeight = (*page3).getheight();
                        // 计算缩小后的宽高（原来的一半）
                        int newWidth = imgWidth;
                        int newHeight = imgHeight / 1.8;
                        loadimage(page3, imagePath, newWidth, newHeight);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg 缩放大小*/
                        putimage(0, 0, page3); // 将图片显示在页面上
                       // break;
                    //}
                        //setCurrentIndex(2); // 点击按钮1时，切换回页面3
                    //cleardevice();5
                    Button* button3_0 = new Button(800, 800, 100, 50, "返回上一页", [&]() {
                        setCurrentIndex(1); // 点击按钮1时，切换回页面2
                        });
                    addButton(2, button3_0); // 将按钮1添加到页面3
                    //FlushBatchDraw(0, 0, 1800, 1600);
                    //cleardevice();
                    addPage(page3);
                    //int last_j = j;
                    //setCurrentIndex(2); // 点击按钮1时，切换回页面3
                //cleardevice();

                });
            addButton(1, button2_j); // 将按钮1添加到页面2
            //cleardevice();
        }
        Button* button2_0 = new Button(800, 500, 100, 50, "返回主界面", [&]() {
            setCurrentIndex(0); // 点击按钮1时，切换回页面1
            });
        addButton(1, button2_0); // 将按钮1添加到页面2
       
        // 强制刷新页面显示
        //flushgraph();
        cleardevice;
        
        });

    addButton(0, button1_2); // 将按钮2添加到页面1
    // 设置初始页面为页面1
    setCurrentIndex(0);

    initStartStationPage();
    initEndStationPage();
    //initTicketCountPage();

#endif
}


// 运行，进入消息循环
void Widget::run()
{
    ExMessage msg;

    BeginBatchDraw(); // 开始批量绘制

    while (true)
    {
        if (peekmessage(&msg)) // 检查是否有消息
        {
            int mouseX = msg.x; // 获取鼠标x坐标
            int mouseY = msg.y; // 获取鼠标y坐标

            switch (msg.message)
            {
            case WM_LBUTTONDOWN: // 鼠标左键按下事件
                mouseClick(mouseX, mouseY); // 处理鼠标点击事件
                break;
            case WM_MOUSEMOVE: // 鼠标移动事件
                mouseMove(mouseX, mouseY); // 处理鼠标移动事件
                break;
            case WM_KEYDOWN:
                switch (msg.ch)
                {
                case VK_ESCAPE:
                    setCurrentIndex(PAGE_INDEX_HOME);
                }
            }
        }

        draw(); // 绘制当前页面内容
        FlushBatchDraw(); // 将缓冲区内容显示在屏幕上
        Sleep(10);
    }

    EndBatchDraw(); // 结束批量绘制
}

// 关闭
void Widget::close()
{
    closegraph(); // 关闭图形环境
}

// 在Widget类中添加新的成员变量
std::string startStation;
std::string endStation;
std::vector<std::string> startStations;
std::vector<std::string> endStations;

void Widget::initStationInfoPage() {
    // 创建新页面
    IMAGE* stationInfoPage = new IMAGE(width, height);
    SetWorkingImage(stationInfoPage);  // 设置工作区为新页面

    // 清空背景
    setbkcolor(WHITE);
    cleardevice();

    // 标题
    settextstyle(30, 0, "楷体");
    settextcolor(BLACK);
    outtextxy(500, 100, "线路信息");

    // 显示站点信息
    displayStationInfo(startStation, endStation);

    // 计算并显示路线
    calculateAndDisplayRoute(startStation, endStation);

    // 添加按钮前先清除之前的按钮
    buttons[4].clear();

    // 继续购票按钮
    Button* continueButton = new Button(400, 700, 200, 50, "继续购票", [this](Button* btn) {
        setCurrentIndex(5);
        initTicketCountPage();
        });
    addButton(4, continueButton);

    // 返回修改按钮
    Button* returnButton = new Button(700, 700, 200, 50, "返回修改", [this](Button* btn) {
        setCurrentIndex(3);
        initEndStationPage();
        });
    addButton(4, returnButton);

    SetWorkingImage();  // 恢复默认工作区
    getimage(stationInfoPage, 0, 0, width, height);
    addPage(stationInfoPage);
}



void Widget::initStartStationPage() {
    // 创建始发站选择页面
    IMAGE* startStationPage = new IMAGE(width, height);
    SetWorkingImage(startStationPage);  // 设置工作区为新页面

    // 清空背景
    setbkcolor(WHITE);
    cleardevice();

    // 设置文字样式
    settextstyle(30, 0, "楷体");
    settextcolor(BLACK);
    outtextxy(500, 100, "请选择始发站");

    // 清除之前可能存在的按钮
    //buttons[2].clear();  // 第2页的按钮

    // 创建输入框按钮
    Button* inputButton = new Button(400, 300, 500, 50, "点击此处输入始发站", [this](Button* btn) {
        char inputStation[100] = { 0 };
        InputBox(inputStation, 100, "请输入始发站名称");

        if (strlen(inputStation) > 0) {
            bool stationFound = false;
            for (int i = 0; i < 304; i++) {
                if (strcmp(station[i].name, inputStation) == 0) {
                    stationFound = true;
                    startStation = inputStation;  // 保存始发站
                    setCurrentIndex(3);  // 切换到终点站选择页面
                    initEndStationPage();
                    break;
                }
            }

            if (!stationFound) {
                MessageBox(GetHWnd(), "您输入的站点不存在，请重新输入", "提示", MB_OK | MB_ICONWARNING);
            }
        }
        });
    addButton(2, inputButton);

    // 返回主界面按钮
    Button* returnButton = new Button(780, 730, 200, 50, "返回主界面", [this](Button* btn) {
        setCurrentIndex(0);
        });
    addButton(2, returnButton);

    SetWorkingImage();  // 恢复默认工作区
    getimage(startStationPage, 0, 0, width, height);
    addPage(startStationPage);
}
void Widget::initEndStationPage() {
    // 创建终点站选择页面
    IMAGE* endStationPage = new IMAGE(width, height);  
    SetWorkingImage(endStationPage);

    // 清空背景
    setbkcolor(WHITE);
    cleardevice();

    // 设置文字样式
    settextstyle(30, 0, "楷体");
    settextcolor(BLACK);
    outtextxy(500, 100, "请选择终点站");

    // 显示已选择的始发站
    std::string startInfo = "已选择的始发站：" + startStation;
    outtextxy(450, 200, startInfo.c_str());

    // 清除之前的按钮
    //buttons[3].clear();

    // 创建输入框按钮
    Button* inputButton = new Button(400, 300, 500, 50, "点击此处输入终点站", [this](Button* btn) {
        char inputStation[100] = { 0 };
        InputBox(inputStation, 100, "请输入终点站名称");

        if (strlen(inputStation) > 0) {
            // 检查输入的站点是否存在且不是始发站
            bool stationFound = false;
            bool isSameStation = false;

            if (strcmp(inputStation, startStation.c_str()) == 0) {
                isSameStation = true;
            }
            else {
                for (int i = 0; i < 304; i++) {
                    if (strcmp(station[i].name, inputStation) == 0) {
                        stationFound = true;
                        endStation = inputStation;
                        setCurrentIndex(4);  // 切换到路线信息页面
                        initStationInfoPage();
                        break;
                    }
                }
            }

            if (isSameStation) {
                MessageBox(GetHWnd(), "终点站不能与始发站相同，请重新输入", "提示", MB_OK | MB_ICONWARNING);
            }
            else if (!stationFound) {
                MessageBox(GetHWnd(), "您输入的站点不存在，请重新输入", "提示", MB_OK | MB_ICONWARNING);
            }
        }
        });
    addButton(3, inputButton);

    // 返回按钮
    Button* returnStartButton = new Button(400, 730, 200, 50, "返回始发站", [this](Button* btn) {
        setCurrentIndex(2);
        initStartStationPage();
        });
    addButton(3, returnStartButton);

    Button* returnMainButton = new Button(780, 730, 200, 50, "返回主界面", [this](Button* btn) {
        setCurrentIndex(0);
        });
    addButton(3, returnMainButton);

    SetWorkingImage();
    getimage(endStationPage, 0, 0, width, height);
    addPage(endStationPage);
}
/*void Widget::initEndStationPage() {
    // 创建终点站选择页面
    IMAGE* endStationPage = new IMAGE(width, height);
    SetWorkingImage(endStationPage);

    // 设置背景颜色
    setbkcolor(WHITE);
    cleardevice();

    // 设置文字样式
    settextstyle(30, 0, "楷体");
    settextcolor(BLACK);
    outtextxy(500, 100, "请选择终点站");

    // 显示已选择的始发站
    std::string startInfo = "已选择的始发站：" + startStation;
    outtextxy(450, 200, startInfo.c_str());

    // 如果已经选择过终点站，显示之前的选择
    if (!endStation.empty()) {
        std::string previousChoice = "上次选择的终点站：" + endStation;
        outtextxy(450, 250, previousChoice.c_str());
    }

    // 准备终点站数据（排除已选择的始发站）
    endStations.clear();
    for (int i = 0; i <= 303; i++) {
        if (strcmp(station[i].name, startStation.c_str()) != 0) {
            bool exists = false;
            for (const auto& existingStation : endStations) {
                if (existingStation == station[i].name) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                endStations.push_back(station[i].name);
            }
        }
    }

    // 创建输入框按钮
   /* Button* inputButton = new Button(400, 300, 500, 50, "点击此处输入终点站", [this]() {
        char inputStation[100] = { 0 };

        // 获取窗口句柄
        HWND hwnd = GetHWnd();

        // 在显示输入框前激活输入法
        HIMC himc = ImmGetContext(hwnd);
        ImmAssociateContext(hwnd, NULL);
        ImmAssociateContext(hwnd, himc);

        InputBox(inputStation, 100, "请输入终点站名称");

        // 释放输入法上下文
        ImmReleaseContext(hwnd, himc);

        if (strlen(inputStation) > 0) {
            bool stationFound = false;
            for (const auto& station : endStations) {
                if (station == inputStation) {
                    stationFound = true;
                    endStation = inputStation;  // 保存终点站
                    setCurrentIndex(4);  // 切换到站点信息显示页面
                    initStationInfoPage();  // 初始化站点信息页面
                    break;
                }
            }

            if (!stationFound) {
                MessageBox(hwnd, "您输入的站点不存在或与始发站相同，请重新输入", "提示", MB_OK | MB_ICONWARNING);
                initEndStationPage();
            }
        }
        });*/
    // 在 initEndStationPage() 中修改输入按钮部分
/*Button* inputButton = new Button(400, 300, 500, 50, "点击此处输入终点站", [this]() {
    char inputStation[100] = { 0 };  // 初始化数组

    // 获取窗口句柄并设置焦点
    HWND hwnd = GetHWnd();
    SetFocus(hwnd);
    
    // 重置并激活输入法
    ImmReleaseContext(hwnd, ImmGetContext(hwnd));
    Sleep(100);  // 短暂延时以确保输入法状态更新
    
    // 重新获取并设置输入法上下文
    HIMC himc = ImmGetContext(hwnd);
    if (himc) {
        ImmSetOpenStatus(himc, TRUE);
        InputBox(inputStation, 100, "请输入终点站名称");
        ImmReleaseContext(hwnd, himc);
    } else {
        InputBox(inputStation, 100, "请输入终点站名称");
    }

    if (strlen(inputStation) > 0) {
        bool stationFound = false;
        for (const auto& station : endStations) {
            if (station == inputStation) {
                stationFound = true;
                endStation = inputStation;
                setCurrentIndex(4);
                initStationInfoPage();
                break;
            }
        }

        if (!stationFound) {
            MessageBox(hwnd, "您输入的站点不存在或与始发站相同，请重新输入", "提示", MB_OK | MB_ICONWARNING);
            initEndStationPage();
        }
    }
});


    addButton(3, inputButton);  // 注意这个按钮添加到页面索引3

    // 返回按钮
    Button* returnStartButton = new Button(400, 800, 200, 50, "返回始发站", [this]() {
        setCurrentIndex(2);
        initStartStationPage();
        });
    addButton(3, returnStartButton);

    Button* returnMainButton = new Button(800, 800, 200, 50, "返回主界面", [this]() {
        setCurrentIndex(0);
        });
    addButton(3, returnMainButton);

    SetWorkingImage();
    getimage(endStationPage, 0, 0, width, height);
    addPage(endStationPage);
}*/

void Widget::displayStationInfo(const std::string& startStation, const std::string& endStation) {
    cleardevice();  // 清空当前页面

    // 设置文字样式
    settextstyle(24, 0, _T("微软雅黑"));
    settextcolor(BLACK);

    int yPos = 250;  // 起始y坐标

    // 显示始发站和终点站
    std::string stationInfo = "始发站：" + startStation + " → 终点站：" + endStation;
    outtextxy(400, yPos, stationInfo.c_str());
    yPos += 40;

    // 获取并显示线路信息
    std::vector<int> startLines = findStationLines(startStation);
    std::vector<int> endLines = findStationLines(endStation);

    // 显示始发站线路
    std::string startLineInfo = "始发站线路：";
    for (size_t i = 0; i < startLines.size(); i++) {
        startLineInfo += std::to_string(startLines[i]) + "号线";
        if (i < startLines.size() - 1) startLineInfo += "、";
    }
    outtextxy(400, yPos, startLineInfo.c_str());
    yPos += 40;

    // 显示终点站线路
    std::string endLineInfo = "终点站线路：";
    for (size_t i = 0; i < endLines.size(); i++) {
        endLineInfo += std::to_string(endLines[i]) + "号线";
        if (i < endLines.size() - 1) endLineInfo += "、";
    }
    outtextxy(400, yPos, endLineInfo.c_str());
}

// 新增辅助函数
std::vector<int> Widget::findStationLines(const std::string& stationName) {
    std::vector<int> lines;
    for (int i = 0; i < NUM_STATIONS; i++) {
        if (station[i].name == stationName) {
            bool exists = false;
            for (int line : lines) {
                if (line == station[i].line) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                lines.push_back(station[i].line);
            }
        }
    }
    return lines;
}
int Widget::setCurrentIndex(int index) {
    if (index >= 0 && index < pages.size()) {
        // 清除当前页面
        cleardevice();

        // 更新索引
        currentIndex = index;

        // 重新绘制页面
        draw();

        // 刷新显示
        FlushBatchDraw();
    }
    return currentIndex;
}
/*void Widget::initializeStationMap() {
    // 清空现有的地图
    stationMap.clear();
    metroMap.clear();  // 新增

    // 第一步：创建所有站点
    for (int i = 0; i < 304; i++) {
        std::string stationName = station[i].name;
        int line = station[i].line;

        // 初始化 metroMap
        if (metroMap.find(stationName) == metroMap.end()) {
            metroMap[stationName] = MetroStation{ line, stationName, {} };
        }

        // 原有的 stationMap 初始化
        if (stationMap.find(stationName) == stationMap.end()) {
            stationMap[stationName] = Station{ stationName, line, {} };
        }
    }

    // 第二步：建立邻接关系
    for (int i = 0; i < 304; i++) {
        for (int j = 0; j < 304; j++) {
            if (i == j) continue;

            std::string station1 = station[i].name;
            std::string station2 = station[j].name;
            int line1 = station[i].line;
            int line2 = station[j].line;

            // 如果是相邻站点（假设数组中相邻的就是实际相邻的站点）
            if (line1 == line2 && abs(i - j) == 1) {
                metroMap[station1].neighbors.push_back(station2);
                metroMap[station2].neighbors.push_back(station1);
            }

            // 如果是换乘站
            if (station1 == station2 && line1 != line2) {
                metroMap[station1].neighbors.push_back(station2);
                metroMap[station2].neighbors.push_back(station1);
            }
        }
    }
}*/
void Widget::initializeStationMap() {
    // 清空现有的地图
    stationMap.clear();

    // 创建所有站点
    for (int i = 0; i < 304; i++) {
        std::string stationName = station[i].name;
        int line = station[i].line;

        // 使用构造函数正确初始化 Station
        if (stationMap.find(stationName) == stationMap.end()) {
            Station newStation(stationName, line);  // 使用构造函数创建新站点
            stationMap[stationName] = newStation;
        }
    }
}



std::vector<RouteStep> Widget::findBestRoute(const std::string& start, const std::string& end) {
    std::queue<std::vector<RouteStep>> queue; // 队列存储路径
    std::set<std::string> visited;            // 记录已访问的站点
    std::vector<RouteStep> result;            // 最优路径

    // 初始化队列
    queue.push({ {start, findStationLine(start)} });
    visited.insert(start);

    while (!queue.empty()) {
        auto currentPath = queue.front();
        queue.pop();
        auto currentStation = currentPath.back();

        if (currentStation.station == end) {
            return currentPath; // 找到目标站点，返回路径
        }

        for (int i = 0; i < NUM_STATIONS; i++) {
            if (station[i].name == currentStation.station) {
                for (int j = 0; j < NUM_STATIONS; j++) {
                    if (strcmp(station[i].name, station[j].name) == 0 && station[i].line != station[j].line) {
                        // 换乘站
                        RouteStep nextStep = { station[j].name, station[j].line };
                        if (visited.find(nextStep.station) == visited.end()) {
                            auto newPath = currentPath;
                            newPath.push_back(nextStep);
                            queue.push(newPath);
                            visited.insert(nextStep.station);
                        }
                    }
                    else if (abs(j - i) == 1 && station[j].line == currentStation.line) {
                        // 直接连接站点
                        RouteStep nextStep = { station[j].name, station[j].line };
                        if (visited.find(nextStep.station) == visited.end()) {
                            auto newPath = currentPath;
                            newPath.push_back(nextStep);
                            queue.push(newPath);
                            visited.insert(nextStep.station);
                        }
                    }
                }
            }
        }
    }
    return {}; // 未找到路径
}





void Widget::calculateAndDisplayRoute(const std::string& start, const std::string& end) {
    auto bestRoute = findBestRoute(start, end);
    if (bestRoute.empty()) {
        outtextxy(400, 200, "未找到有效路线");
        return;
    }

    int yPos = 200;
    settextstyle(24, 0, "楷体");

    for (size_t i = 0; i < bestRoute.size(); i++) {
        std::string stepInfo;
        if (i == 0) {
            stepInfo = "从 " + bestRoute[i].station + " 乘坐 " + std::to_string(bestRoute[i].line) + " 号线";
        }
        else if (bestRoute[i].line != bestRoute[i - 1].line) {
            stepInfo = "在 " + bestRoute[i - 1].station + " 换乘 " + std::to_string(bestRoute[i].line) + " 号线";
        }
        stepInfo += " → " + bestRoute[i].station;
        outtextxy(400, yPos, stepInfo.c_str());
        yPos += 30;
    }
}

int Widget::findStationLine(const std::string& stationName) {
    for (int i = 0; i < 304; i++) {
        if (stationName == station[i].name) {
            return station[i].line; // 返回该站点的线路编号
        }
    }
    return -1; // 如果找不到，返回 -1 表示无效线路
}

std::vector<int> Widget::findStationIndexes(const std::string& stationName)
{
    std::vector<int> indexes;

    for (int i = 0; i < NUM_STATIONS; i++) {
        if (station[i].name == stationName) {
            indexes.push_back(i);
        }
    }

    return indexes;
}

std::vector<StationInfo> Widget::getStationInfo()
{
    std::vector<StationInfo> stationInfo;
    for (int i = 0; i < NUM_STATIONS; i++)
    {
        StationInfo info;
        info.index = i;
        //查找相同名字的站点
        std::vector<int> indexes = findStationIndexes(station[i].name);
        for (int index : indexes)
        {
            //可以到达的有前一个和后一个
            if (index - 1 >= 0 && station[index].line == station[index - 1].line) {
                info.nextIndex.push_back(index - 1);
            }
            if (index + 1 < NUM_STATIONS && station[index].line == station[index + 1].line) {
                info.nextIndex.push_back(index + 1);
            }
        }
        stationInfo.push_back(info);
    }

    return stationInfo;
}

struct StationPath {
    StationPath* prev;  // 指向前一个节点
    int index;// 当前站点的索引
    std::vector<StationPath*> next;// 当前站点的下一站
    StationPath() {
        prev = NULL;
        index = -1;
    }
};

void clearStationPath(StationPath* path)
{
    std::queue<StationPath*> tempNext;
    tempNext.push(path);
    while (!tempNext.empty()) {
        StationPath* current = tempNext.front();
        tempNext.pop();
        for (auto next : current->next) {
            tempNext.push(next);
        }
        delete current;
    }
}

std::vector<RouteStep> Widget::findShortestRoute(const std::string& start, const std::string& end)
{
    //只获取一次
    if (stationInfo.size() == 0) {
        stationInfo = getStationInfo();
    }

    //查找开始点的位置
    std::vector<int> startIndexes = findStationIndexes(start);
    std::vector<StationPath*> paths;
    std::vector<StationPath*> ends;
    for (int i = 0; i < startIndexes.size(); i++) {
        bool finished = false;
        std::set<int> visited; // 记录已访问的站点
        StationPath* path = new StationPath();
        path->prev = NULL;
        path->index = startIndexes[i];
        visited.insert(path->index);
        std::vector<StationPath*> nextPaths;
        nextPaths.push_back(path);
        while (!finished) 
        {
            std::vector<StationPath*> tempPaths;
            for (auto next : nextPaths) {
                for (auto nextStation : stationInfo[next->index].nextIndex) {
                    // 判断是否已经访问过
                    if (visited.find(nextStation) == visited.end()) {
                        StationPath* temp = new StationPath();
                        temp->prev = next;
                        temp->index = nextStation;
                        next->next.push_back(temp);
                        tempPaths.push_back(temp);
                        //判断是否到达终点
                        if (station[stationInfo[nextStation].index].name == end) {
                            finished = true;
                            ends.push_back(temp);
                        }
                    }
                }
            }
            nextPaths = tempPaths;
            //没有找到符合条件的路径
            if (tempPaths.size() == 0) {
                clearStationPath(path);
                path = nullptr;
                break;
            }
        }
        //找到了路径才要添加
        if (finished && path) {
            paths.push_back(path);
        }
    }

    if (ends.size() == 0) {
        return std::vector<RouteStep>();
    }

    //根据路径来添加
    std::vector<std::vector< RouteStep> > routes;
    for (auto path : ends) {
        StationPath* current = path;
        std::vector<RouteStep> route;
        while (current) {
            RouteStep step;
            step.line = station[current->index].line;
            step.station = station[current->index].name;
            route.push_back(step);
            current = current->prev;
        }
        routes.push_back(route);
    }

    //释放所有路径
    for (auto path : paths) {
        clearStationPath(path);
    }

    //判断最短路径
    int shortestPath = 0;
    for (int i = 1; i < routes.size(); i++) {
        if (shortestPath > routes.size()){
            shortestPath = i;
        }
    }

    std::reverse(routes[shortestPath].begin(), routes[shortestPath].end());

    return  routes[shortestPath];
}


void Widget::initTicketCountPage() {
    // 创建票数选择页面
    IMAGE* ticketCountPage = new IMAGE(width, height);
    SetWorkingImage(ticketCountPage);  // 设置工作区为新页面

    // 设置背景
    setbkcolor(WHITE);
    cleardevice();

    // 绘制文字
    settextstyle(30, 0, "楷体");
    outtextxy(500, 200, "请选择购票数量");

    // 票数选择按钮
    for (int tickets = 1; tickets <= 5; tickets++) {
        Button* ticketButton = new Button(
            500 + (tickets - 1) * 150,
            400,
            100, 50,
            std::to_string(tickets) + "张",
            [&, tickets](Button* btn) {
                std::cout << "选择了" << tickets << "张票" << std::endl;
            }
        );
        addButton(5, ticketButton);
    }

    // 返回站点信息页面按钮
    Button* returnButton = new Button(600, 750, 200, 50, "返回上一页", [&](Button* btn) {
        setCurrentIndex(4);
        });
    addButton(5, returnButton);

    SetWorkingImage();  // 恢复默认工作区
    getimage(ticketCountPage, 0, 0, width, height);
    addPage(ticketCountPage);
}

void Widget::setPage(int index, IMAGE* page)
{
    //判断索引是否有
    if (index < 0) {
        return;
    }
    if (index >= pages.size()) {
        pages.resize(index + 1);
        buttons.resize(index + 1);
    }
    pages[index] = page;
    buttons[index] = std::vector<Button*>();
}








