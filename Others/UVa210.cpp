#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
using namespace std;
/***********
1.关键题意：
1.1
1.1 对变量再次上锁的程序会被挂起，其他没被挂起的程序仍然可以操作变量，哪怕变量已经被其他程序锁住。
1.2 unlock时，只从阻止队列里拿一个出来到等待队列中，并从lock开始执行。
2.思路
主要考虑需要存储哪些中间变量，以及边界条件。
框架搭好了就是找bug了k。
3.卡壳点
3.1如何处理一整行的输入？
3.2题目关于锁与解锁的理解，一些中文翻译漏了一些题意，英文原文才是完整的。
3.3VOJ比题意描述多了一个输入测试用例。
**********/


int stm_process(string s)
{
    switch (s[2])
    {
        case '=':return 0;//赋值
        break;
        case 'i':return 1;//打印
        break;
        case 'c':return 2;//锁定
        break;
        case 'l':return 3;//解锁
        break;
        case 'd':return 4;//end
        break;
        default:return -1;
        break;
    }
}
int get_value(string s)
{
    int value = 0;
    for (int i = 4; i < s.length(); i++)
    {
        value = (value*10 + s[i]-'0');
    }
    return value;
}
int get_var(string s)
{
    return s[6];
}
int main()
{
    int T;
    cin >> T;
    while(T--)//VOJ没有说明有测试用例数，卡了好久WA
    {
        int n, t[5], Q, vars[26] = {0};
        vector< vector<string> > Program;
        vector<string> statements;
        cin >> n;
        vector< int > cur_statement(n,0);
        for (int i = 0; i < 5; i++)
        {
            cin >> t[i];
        }
        cin >> Q;
        int Pcount = 0, Scount = 0;
        string temp;
        deque<int> wait_queue;
        queue<int> block_queue;
        cin.get();
        while(Pcount < n)
        {
            getline(cin,temp);
            if (temp != "end")
            {
                statements.emplace_back(temp);
                Scount ++;
            }
            else
            {
                statements.emplace_back(temp);
                Program.emplace_back(statements);
                statements.clear();
                wait_queue.push_back(Pcount);
                Pcount ++;
            }
        }
        int P_id, cur_t = 0;
        bool  locked = false;
        while(!wait_queue.empty())
        {
            P_id = wait_queue.front();
            wait_queue.pop_front();
            wait_queue.push_back(P_id);
            cur_t = 0;
            while(cur_t < Q)
            {
                string statement = Program[P_id][cur_statement[P_id]];
                int type = stm_process(statement);
                if (type == 2)
                {
                    //lock
                    if (locked)
                    {
                        block_queue.push(P_id);
                        wait_queue.pop_back();
                        break;
                    }
                    else
                    {
                        locked = true;
                    }
                }
                else if (type == 3)
                {
                    //unlock
                    locked = false;
                    if (!block_queue.empty())
                    {
                        wait_queue.push_front(block_queue.front());
                        block_queue.pop();
                    }
                }
                else if(type == 4)
                {
                    //end
                    wait_queue.pop_back();
                    break;
                }
                else if (type == 0)
                {
                    //assignment
                    int pos = statement[0] - 'a';
                    vars[pos] = get_value(statement);
                }
                else if(type == 1)
                {
                    //print
                    int pos = get_var(statement) - 'a';
                    printf("%d: %d\n",P_id+1,vars[pos]);
                }
                cur_statement[P_id] ++;
                cur_t += t[type];
            }
        }
        if(T)
            printf("\n");
    }
    return 0;
}
