#include <array>
#include <iostream>

/**
 * @brief Backtracking alorithm
 * @namespace backtracking
 */
namespace backtracking{
/**
 * @brief Functions for the [Knight;s tour] algorithm
 * 
 */
    namespace knight_tour{

        /**
         * @brief A utility function to check if i,j are valid indexes for N*N chessboard
         *        (检查i,j是否是N*N棋盘上的有效索引)
         * 
         * @tparam V  number of vertices in array
         * @param x   current index in rows
         * @param y   current index in colums
         * @param sol  matrix where numbers are saved
         * @return true 
         * @return false 
         */
        template<size_t V>  //size_t 类型表示C中任何对象所能达到的最大长度，它是无符号整数
        bool issafe(int x, int y, int mov, const std::array<std::array<int,V>, V> &sol,
                    const std::array<int,V> &xmov, std::array<int,V> &ymov)
        {
             return (x < V && x >= 0 && y < V && y >= 0 && sol[x][y] == -1);
        }

        template<size_t V>
        bool solve(int x,int y,int mov,std::array<std::array<int,V>, V>&sol,const std::array<int, V>& xmov,std::array<int,V>&ymov)
        {
            int k = 0, xnext = 0, ynext = 0;
            if(mov == V*V)
            {
                return true;
            }

            for(k = 0; k < V; k++)
            {
                xnext = x + xmov[k];
                ynext = y + ymov[k];

                if(issafe<V>(xnext,ynext,mov + 1,sol,xmov,ymov) == true)
                {
                    return true;
                }else{
                    sol[xnext][ynext] = -1;
                }
            }
            return false;          
        }

    }

}

int main()
{
    const int n = 8;
    std::array<std::array<int,n>,n> sol = {0};
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            sol[i][j] = -1;
        }
    }

    std::array<int,n> xmov = {2,1,-1,-2,-2,-1,1,2};
    std::array<int,n> ymov = {1,2,2,1,-1,-2,-2,-1};

    sol[0][0] = 0;

    bool flag = backtracking::knight_tour::solve<n>(0,0,1,sol,xmov,ymov);
    if(flag == false)
    {
        std::cout<<"Error: Solution does not exist\n";
    }else
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                std::cout<<sol[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }
    return 0;
}