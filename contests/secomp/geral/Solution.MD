# Solucoes dos problemas da prova inciante

- Increasing Array
    - Ideia
        > A ideia e receber todos os valores e gardando o valor da posicao anterior. Assim para qualquer $a_i$ sendo o valor da posicao $i$ podemos verificar se $a_i >= a_{i-1}$, caso a essa condicao seja falsa, ou seja $a_i < a_{i-1}$, devemos aumentar o valor de $a_i$ ate que $a_i = a_{i-1}$, ja que 
        > - Esse e a menor quantidade de movimentos que podemos fazer no momento
        > - Isso faz com que o valor de $a_{i-1}$ seja o menor possivel na proxima iteracao
    - Codigo
        ```
            #include<bits/stdc++.h>
            using namespace std;

            #define int long long

            signed main()
            {
                int n;
                cin >> n;

                int last; cin >> last;

                int moves = 0;

                for(int i = 1; i < n; i++)
                {
                    int a; cin >> a;

                    if(a < last)
                    {
                        moves += last - a;

                        a = last;
                    }

                    last = a;
                }

                cout << moves << endl;

                return 0;
            }
        ```

- Prefiquence
    - Ideia
        > É uma questão que se baseia na ideia de two pointers para fazer a contagem do tamanho. Se deixam dois ponteiros $pn$ e $pm$ respectivamente nas posições iniciais de n e m. Dai avançamos $pm$ de posição continuamente e sempre que $m[pm] == n[pn]$ fazemos pn apontar para a posição da frente. Dai ao final, quando n se for mais possivel avançar posições com $pm$ ou $pn$, acabamos a execução e dizemos em que posições de n $pm$ está.
    - Codigo
        ```
            #include<bits/stdc++.h>
            using namespace std;

            #define int long long

            signed main()
            {
                int t; cin  >> t;

                while(t--) // executa o loop t vezes
                {
                    int sn, sm;
                    string n,m; 
                    cin >> sn >> sm >> n >> m;

                    int pn = 0, pm = 0;

                    while(pn < sn && pm < sm)
                    {
                        if(n[pn] == m[pm])
                            pn++;
                        pm++;
                    }

                    cout << pn << endl;

                }

                
                return 0;
            }
        ```


- K-th Beautiful String 
    - Ideia
        > A ideia da questão é bem simples, devemos pegar a soma de todos os elementos dentro de um range. A questão é: Uma solução quadradica ou seja, $O(n^2)$, não passa a tempo. Assim devemos apelar para alguma estratégia diferente de um loop de $a$ até $b$ para cada uma das queries, nesse caso sendo muito conveniente usar a prefix sum. Com a soma de prefixos fazemos que na posição $i$ do vetor, seja guardada a soma acumulada dos valores da posição 0 até a posição $i$, assim convenientemente conseguimos fazer queries em $O(1)$ usando a seguite logica
        > - $sum(a, b) = pref[b] - pref[a-1].$
        >
        > O funcionamento deve ficar bem claro com o seguinte exemplo
        >
        > - $sum(2, 4) = pref[4] - pref[1]$ 
        >
        > - = $(val[4] + val[3] + val[2] + val[1] + val[0]) - pref[1]$
        >
        > - = $(val[4] + val[3] + val[2] + val[1]) - (val[1])$
        >
        > - = $val[4] + val[3] + val[2].$
        >


    - Codigo
        ```
            #include<iostream>
            using namespace std;

            #define int long long

            

            signed main()
            {
                int n, q; cin >> n >> q;

                int pref[1000000] = {0}; // Faz APENAS a primeira posição de pref = 0

                for(int i = 1; i <= n; i++)
                {
                    cin >> pref[i];
                    sum[i] += pref[i-1];
                }

                while(q--)
                {
                    int a, b; cin >> a >> b;

                    cout << pref[b] - pref[a-1] << endl;
                }

                return 0;
            }
        ```

- Coin Games  
    - Ideia
        > Nessa questão voce acaba pensando muito tempo em como simular o comportamento otimo, mas nesse caso nem é necessário, basta simular usando um criterio qualquer e contar o numero de jogadas.
    - Codigo
        ```
        #include <bits/stdc++.h>
        
        using namespace std;
        
        #define int long long

        string s;

        char invert(char c)
        {

            if(c=='U') return 'D';
            return 'U';
        }

        int sim()
        {
            int cont = 0;


            while(s.size())
            {
                // cout << s << endl;
                bool flag = true;
                for(int i = 0; i < s.size(); i++)
                {
                    if(s[i] == 'D')
                        continue;

                    flag = false;  
                    
                    if(i == 0)
                        s[s.size()-1] = invert(s.back());
                    else
                        s[i-1] = invert(s[i-1]);

                    if(i == s.size() -1)
                        s[0] = invert(s[0]);
                    else
                        s[i+1] = invert(s[i+1]);
                    
                    s.erase(i, 1);
                    break;
                }

                if(flag)
                    return cont;

                cont++;
            }
            return cont;
        }
        
        void solve()
        {
            int n;
            cin >> n;

            cin >> s;

            cout << (sim()%2 ? "YES" : "NO") << endl;

        }

        signed main()
        {

            int t = 1; 
            cin >> t;

            while(t--)
                solve();

            
            return 0;
        }   
        ```
- Good kid
    - Ideia
        > Quanto maior for o menor numero maior vai ser o resultado. Entao basta achar o menor numero, aumenta-lo e dizer o produto.
    - Codigo
        ```
        #include<bits/stdc++.h>
        using namespace std;

        #define int long long

        void solve()
        {

            int n; cin >> n;

            vector<int> v(n); // vetor de n posicoes

            int menor = 1000, minpos = -1;   

            for(int i = 0; i < n; i++)
            {
                cin >> v[i];

                if(menor > v[i])
                {
                    menor = v[i];
                    minpos = i;
                }
            }

            v[minpos]++;

            int prod = 1;

            for(auto & i : v)
                prod *= i;

            cout << prod << endl;
        }

        signed main()
        {
            int t = 1; 
            cin >> t;

            while(t--)
                solve();

            return 0;
        }
        ```
- Fatigue-Fighting Vacation 
    - Ideia
        # AAAAAAAA
- String Matching 
    - Ideia
        > Consiste na implementação direta de algum algoritmo de busca de padroes em string em tempo linear (abaixo fiz usando KMP, mas podem buscar tambem pelo algoritmo Z ou fazer por Hashing)
    - Codigo
        ```
        #include<bits/stdc++.h>
        
        using namespace std;
        
        void compute_lps_array(const string & s, int  arr[])
        {
            int n = s.size();
        
            arr[0] = 0;
        
            int i = 1;
            int len = 0;
            while(i < n)
            {
                if(s[len] == s[i])
                {
                    arr[i] = ++len;
                    i++;
                }
                else if(len != 0)
                    len = arr[len-1];
                else
                    arr[i++] = 0;
            }
        }
        
        int lps[10000000];
        int KMP(const string & s, const string & pat, int lps[])
        {
            int occur = 0;
            int n = s.size();
            int m = pat.size();
        
            int i = 0, j = 0;
        
            while(!(m - j > n - i) )
            {
                if(s[i] == pat[j])
                {
                    i++;j++;
        
                    if(j == m)
                    {
                        occur++;
                        j = lps[j-1];
                    }
                }
                else if(j!= 0)
                    j = lps[j-1];
                else
                    i++;
            }
        
            return occur;
        }
        
        int main()
        {
        
            string source, pat;
            cin >> source >> pat;
        
        
            compute_lps_array(pat, lps);
        
            cout << KMP(source, pat, lps) << endl;
        
            return 0;
        }
        ```
- Maximum Subarray Sum 
    - Ideia
        > Buscando em todos os ranges, ja considerando o uso de uma prefix sum, teriamos uma complexidade $O(n^2)$ que nesse caso é inviavel. Então podemos usar apenas uma estrategia simples em tempo linear. Iteraremos pelo array e guardaremos em cada iteração o maior valor de soma de possivel até aquele momento (chamarei de acul), assim, caso $acul + arr[i] > 0$ significa que vale a pena passar esse valor para frente, já que, por ser positivo ele pode ajudar a incrementar os valores futuros, já caso  $acul + arr[i] < 0$, significa que esse valor acumulado atrapalhará a soma daqui pra frente, então, preferimos zerar o range otimo, fazendo ele começar na proxima iteração, e passando a soma acumulada de 0. Assim, basta a cada passo fazer uma verificação de qual o maior valor. 
    - Codigo
        ```
        #include<bits/stdc++.h>
        
        using namespace std;
       
        
        int main()
        {
        
            int n; cin >> n;

            int best_sum = 0, acul = 0;

            while(n--)
            {
                int aux; cin >> aux;
                acul += aux;

                best_sum = max(best_sum, acul);

                acul = max(acul, 0);
            }

            cout << best_sum << endl;
        
            return 0;
        }
        ```

- Rudolf and 121 
    - Ideia
        > Devemos simular as operações descritas da seguinte maneira. Na primeira posição só é possivel zerar usando a operação da posição a frente e assim fazemos. Agora como ja chegamos a 0 na posição inicial devemos zerar a segunda posição, que por usa vez não pode mais receber a operação (já que deixaria a primeira negatica), assim novamente delegamos a responsabilidade para a posição da frente. É possivel fazer algo analogo do fim para o começo. 
    - Codigo
        ```
        #include<bits/stdc++.h>
            
        // #define int long long int
        #define all(A) A.begin(), A.end()
            
        using namespace std;

        int values[200001];

        int solve()
        {
            int n; cin >> n;

            for(int i = 0; i < n; i++)
                cin >> values[i];

            for(int i = 0; i < n - 2; i++)
            {
                values[i+1] -= values[i] * 2;
                values[i+2] -= values[i];
                values[i] = 0;


                // Caso os proximos 2 ficarem negativos significa que e impossivel
                if(	values[i+1] < 0  || values[i+2] < 0)
                    return 0;
            }
            
            // Verificando ao final os final se os dois ultimos valores estao zerados, ja que sao os unicos que nao garantimos pelo metodo mostrado 
            if(values[n-1] != 0 || values[n-2] != 0)
                return 0;

            return 1;
        }
            
        signed main()
        {
            int t; cin >> t;

            while(t--)
                cout << (solve() ? "YES" : "NO") << endl;
            
            
            return 0;
        } 
        ```

- Monsters 
    - Ideia
        > Pela logica de passos a cada turno, e interessante que tenhamos uma busca homogenea pelo grid, por isso usaremos o BFS. Assim, para simular os espacos que os monstros podem estar a cada passo, marcaremos a area de monstros se movimentando com um M no grid. Ja para simular a area de movimentacao do jogador, marcaremos no grid um A em todas as posicoes em que o jogador pode estar em cada passo. E importante ressaltar que: Um monstro pode entrar na area em que o jogador ocupa, mas o contrario e FALSO. Desse modo quando encontrarmos um A e uma das bordas do grid saberemos que e possivel. Ja caso em nenhum momento isso aconteca, significa que os monstros restringiram o movimento do jogador de modo que isso seja impossivel.
        >
        > De modo mais tecnico, para simular isso devemos inciar a fila do bfs com todos os monstros que encontrarmos e, no final, inserir o jogador. E preciso tambem passar uma flag, dizendo se o elemento da fila e um monstro ou o jogador e a cada passo do bfs propagar essa flag. Fora isso, para cada movimento do jogador E APENAS DO JOGADOR, devemos indicar de que outra posicao chegamos, para que seja possivel mapear o caminho 
    - Codigo
        ```
        #include<bits/stdc++.h>
        
        #define int long long
        #define all(A) A.begin(), A.end()
        
        using namespace std;
        typedef vector<vector<int>> graph_type;
        
        #define INF 200000
        
        char g[1000][1000];
        int n, m;
        
        struct movement
        {
            pair<int , int> vec;
            char direction;
        };
        
        vector<movement> moves =
        {
            {{1, 0}, 'D'},	
            {{0, -1}, 'L'},	
            {{0, 1}, 'R'},	
            {{-1, 0}, 'U'}	
        };
        
        movement parent [1000][1000];
        
        pair<int, int> bfs(pair<int , int> player, vector<pair<int, int>> & monsters)
        {
        
            queue<movement> order;
        
            parent[player.first][player.second] = {{-1, -1}, '\0'};
            for(auto m : monsters)
                order.push({m, 'M'});
            order.push({player, 'A'});
        
            while(!order.empty())
            {
                auto [pos, type] = order.front();
                // auto [y, x] = pos;
                order.pop();
                
                if((pos.second == 0 || pos.first == 0 || pos.first == n-1 ||pos.second == m-1) && type == 'A')
                    return pos;
        
                // if(y < 0 || y >=n || x <0 || x>=m)
        
                for(auto [vec, direction] : moves)
                {
                    int x = pos.second + vec.second, y = pos.first + vec.first;
                    if(y < 0 || y >=n || x <0 || x>=m)
                        continue;
        
                    
        
                    if(g[y][x] == '.' || (type == 'M' && g[y][x] == 'A'))
                    {
                        g[y][x] = type;
                        order.push({{y, x}, type});
        
                        if(type == 'A')
                            parent[y][x] = {pos, direction};
                    }
        
                }
            }
        
        
            return {-1, -1};
        }
        
        signed main()
        {
            cin >> n >> m;
            
            vector<pair<int, int>> monsters;
            pair<int , int> player;
        
            for(int y = 0; y < n; y++)
            {
                for(int x = 0; x < m; x++)
                {
                    cin >>g[y][x];
                    if(g[y][x] == 'M')
                        monsters.push_back({y,x});
                    else if(g[y][x] == 'A')
                        player = {y,x};
                }
            }
        
            pair<int, int> curr = bfs(player, monsters);
        
            if (curr.first == -1)
                return cout << "NO\n", 0;
        
            // cout << curr.second << ' ' << curr.first << endl;
        
            string ans;
        
            while (curr.first != -1)
            {
                auto [p, d] = parent[curr.first][curr.second];
        
                if(d != '\0')
                    ans +=d;
        
                curr = p;
            }
        
        
            reverse(all(ans));
            cout << "YES\n" << ans.size() << endl << ans << endl;
            
            
        
            return 0;
        }
        ```


- Subarray Sums II  
    - Ideia
        > Se fizermos uma prefix sum e buscarmos em todos os ranges teremos novamente um algoritmo $O(n^2)$, entao devemos buscar outro modo de fazer isso. 
        >
        > Sabendo que o que queremos e
        >
        > - $x = pref[b] - pref[a-1] =>$
        > - $pref[a-1] = x - pref[b]$
        >
        > com essa observacao podemos guardar a frequencia de cada valor $pref[i]$, e entao, consultar a frequencia de $x - pref[i]$ conforme vamos iterando e gerando a prefix sum. Considerando que vamos salvar isso em um map, no fim teremos complexidade $O(nlog(n))$.
    - Codigo
        ```
        #include<bits/stdc++.h>
        
        #define int long long
        #define all(A) A.begin(), A.end()
        
        using namespace std;
        typedef vector<vector<int>> graph_type;
        
        #define INF 200000
        
        char g[1000][1000];
        int n, m;
        
        struct movement
        {
            pair<int , int> vec;
            char direction;
        };
        
        vector<movement> moves =
        {
            {{1, 0}, 'D'},	
            {{0, -1}, 'L'},	
            {{0, 1}, 'R'},	
            {{-1, 0}, 'U'}	
        };
        
        movement parent [1000][1000];
        
        pair<int, int> bfs(pair<int , int> player, vector<pair<int, int>> & monsters)
        {
        
            queue<movement> order;
        
            parent[player.first][player.second] = {{-1, -1}, '\0'};
            for(auto m : monsters)
                order.push({m, 'M'});
            order.push({player, 'A'});
        
            while(!order.empty())
            {
                auto [pos, type] = order.front();
                // auto [y, x] = pos;
                order.pop();
                
                if((pos.second == 0 || pos.first == 0 || pos.first == n-1 ||pos.second == m-1) && type == 'A')
                    return pos;
        
                // if(y < 0 || y >=n || x <0 || x>=m)
        
                for(auto [vec, direction] : moves)
                {
                    int x = pos.second + vec.second, y = pos.first + vec.first;
                    if(y < 0 || y >=n || x <0 || x>=m)
                        continue;
        
                    
        
                    if(g[y][x] == '.' || (type == 'M' && g[y][x] == 'A'))
                    {
                        g[y][x] = type;
                        order.push({{y, x}, type});
        
                        if(type == 'A')
                            parent[y][x] = {pos, direction};
                    }
        
                }
            }
        
        
            return {-1, -1};
        }
        
        signed main()
        {
            cin >> n >> m;
            
            vector<pair<int, int>> monsters;
            pair<int , int> player;
        
            for(int y = 0; y < n; y++)
            {
                for(int x = 0; x < m; x++)
                {
                    cin >>g[y][x];
                    if(g[y][x] == 'M')
                        monsters.push_back({y,x});
                    else if(g[y][x] == 'A')
                        player = {y,x};
                }
            }
        
            pair<int, int> curr = bfs(player, monsters);
        
            if (curr.first == -1)
                return cout << "NO\n", 0;
        
            // cout << curr.second << ' ' << curr.first << endl;
        
            string ans;
        
            while (curr.first != -1)
            {
                auto [p, d] = parent[curr.first][curr.second];
        
                if(d != '\0')
                    ans +=d;
        
                curr = p;
            }
        
        
            reverse(all(ans));
            cout << "YES\n" << ans.size() << endl << ans << endl;
            
            
        
            return 0;
        }
        ```

