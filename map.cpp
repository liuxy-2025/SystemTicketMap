#include "map.h"
struct name_matrix
{
    int line;
    const char name[30];
    const char ENGname[100];
};
struct name_matrix station[304] = { { 1,"机场东","Airport_East" },{1,"后瑞","Hourui" },{1,"固戍","Gushu"},{1,"西乡","Xixiang"},
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
                                           {2,"莲塘","Liantang"},{ 3,"福保","Futian_Bonded_Area" },
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
                                           {5, "黄贝岭","Huangbeiling" } };
enum State { INTERFACE1, INTERFACE2 };  // 枚举表示界面1和界面2   
void StationToQuery()
{
beginning:State currentState = INTERFACE1;
    setbkcolor(RGB(255, 255, 255));
	settextcolor(BLACK);
	settextstyle(30, 20, _T("黑体"));
	outtextxy(520, 400, _T("欢迎来到地铁售票系统，请选择以下功能"));
	setfillcolor(RGB(192, 192, 192));
	solidrectangle(500, 500, 700, 550);
	solidrectangle(1050, 500, 1250, 550);
	settextstyle(30, 10, _T("华文楷体"));
	setbkmode(TRANSPARENT);
	outtextxy(510, 510, _T("购买地铁票"));
	outtextxy(1060, 510, _T("查询线路"));
	int x1, y1,x2,y2;
	while (true)
	{
		if(currentState == INTERFACE1 && MouseHit())
		{  // 检查是否有鼠标消息
			MOUSEMSG mmsg1 = GetMouseMsg();  // 获取鼠标消息
            if (mmsg1.uMsg == WM_LBUTTONDOWN)
            {  // 检测左键点击
                x1 = mmsg1.x;
                y1 = mmsg1.y;
                if (x1 >= 1040 && x1 <= 1260 && y1 >= 490 && y1 <= 560)
                {
                    setbkcolor(0xeeeeee);
                    cleardevice();
                    settextcolor(BLACK);
                    //outtextxy(120, 50, _T("请输入您要查询的站点"));
                    //while (true)
                    //{
                        //msg = getmessage(EX_MOUSE);			// 获取消息输入

                    char s[1000];
                    char str[100][100];
                    InputBox(s, 1000, _T("请输入您要查询的站点"));
                    int ifound = 0;
                    cleardevice();
                    for (int i = 0; i <= 303; i++)
                    {

                        if (strcmp(s, station[i].name) == 0)
                        {
                            ifound++;
                            sprintf_s(str[ifound], "%d", station[i].line);

                        }

                    }
                    if (ifound)
                    {
                        for (int j = 1; j <= ifound; j++)
                        {
                            outtextxy(120, 100, "你查询的站点有以下线路");
                            outtextxy(100 + j * 70, 150, str[j]);
                            outtextxy(100 + j * 78, 150, "号线");
                            outtextxy(120, 200, "请点击数字查询详细地铁线路图");
                        }

                    }
                    if (!ifound)
                        outtextxy(120, 200, _T("您输入的站点不存在"));
                    setfillcolor(RGB(193, 193, 193));			// 设置填充颜色
                    fillrectangle(710, 700, 870, 730);
                    outtextxy(720, 700, "返回主界面");
                    currentState = INTERFACE2; 

                        //for (int k = ifound; k >= 0; k--)
                        //{
                            //if (x >= 100 + k*70&&x<=100+(k+1)*70&&y<=180&&y>=140)

                       // }

                }
            }
        }
        while (MouseHit() && currentState == INTERFACE2)
        {
            //printf_s("检测到鼠标点击");
            MOUSEMSG mmsg2 = GetMouseMsg();
            if (mmsg2.uMsg == WM_LBUTTONDOWN)
            {

                x2 = mmsg2.x;
                y2 = mmsg2.y;
                printf_s("%d,%d", x2, y2);
                if (x2 >= 700 && x2 <= 850 && y2 >= 690 && y2 <= 740)
                {
                    printf_s("成功点击");
                    cleardevice();
                    goto beginning;
                }
                //if (x2 >= 700 && x2 <= 850 && y2 >= 690 && y2 <= 740)
             }
        }
	}
}