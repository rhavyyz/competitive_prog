# Solucoes dos problemas da prova inciante
- Watermelon

    - Ideia
        > A questao consiste basicamente em verificar se e possivel dividir um inteiro $w$ em dois valores pares. Facil ver que e impossivel para todo e qualquer numero impar, ja que compor um numero impar pela soma e possivel apenas fazendo $impar + par$. Ja para numeros pares maiores que 2 podemos dividir em $2, w-2$. E para pares menores que 2 (o proprio 2 e 0) podemos muito rapidamente verificar que nao e possivel.

    - Codigo
        ```
            #include<iostream>
            using namespace std;

            int main()
            {
                int w;
                cin >> w;

                if(w%2 == 0 && w > 2)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;

                return 0;
            }
        ```

- Weird Algorithm
    - Ideia
        > A solucao consiste em literalmente simular os passos que foram descritos no enunciado. Unico detalhe especial dessa questao e que durante a simulacao o valor de $n$ pode sair dos limites de um inteiro normal. Por isso se deve usar o long long
    
    - Codigo
        ```
            #include<iostream>
            using namespace std;

            #define int long long

            signed main()
            {
                int n;
                cin >> n;

                while(cout << n << ' ', n != 1 ) // o que vem antes da virgula e executado como em um do while e o que esta apos a virgula e a condicao
                {

                    if(n % 2 == 0)
                        n /= 2;
                    else
                        n = n*3 +1; 
                }

                cout << endl;

                return 0;
            }
        ```

- Missing number
    - Ideia
        > A ideia e durante a leitura registrar em um vetor os numeros que forem recebidos. Apos a leitura do input basta percorrer o vetor com e assim que achar um numero que nao foi registrado usa-lo de output.
    
    - Codigo
        ```
            #include<bits/stdc++.h>
            using std::memset, std::cin, std::cout, std::endl;

            #define int long long

            bool numbers[2 * (int)1e5 + 1]; 
            // false caso nao tenha sido a achado e true caso o contrario

            signed main()
            {
                int n;
                cin >> n;

                memset(numbers, false, sizeof(bool) * n);// definindo o valor de todas as posicoes do vetor como true 


                for(int i = 1; i < n; i++)
                {
                    int aux; cin >> aux;

                    numbers[aux] = true;
                }


                for(int i = 1; i <= n; i++)
                {
                    if(!numbers[i])
                        cout << i << endl;
                }


                return 0;
            }
        ```

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

- Divisibility Problem
    - Ideia
        > A ideia e literalmente achar quantas unidades faltam para tornar o a divisivel por b. Com a operacao de MOD sabemos quantas sobram na divisao. Assim basta fazer o complemento desse valor.
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
                    int a, b;
                    cin >> a >> b;

                    int sobra = a % b;

                    int res = 0;

                    if(sobra > 0)
                        res = b - sobra;

                    cout << res << endl;

                }

                
                return 0;
            }
        ```


- K-th Beautiful String 
    - Ideia
        > Em suma, o que define a posicao na ordem lexicografica sao as posicoes dos 2 b`s, entao para achar a kezima string devemos achar essas posicoes. Vamos buscar as posicoes de forma invertida ja que desse jeito a, ao menos pra mim, fica mais simples de entender. Com posicoes invertidas quero dizer que as a ultima posicao da string teria o index 0, enquanto a primeira teria o index $n-1$
        > - aa $b_0b_1$  :  $b_0$ esta na posica 1, $b_1$ esta na posicao 0 
        >
        > Se escrevermos algumas strings em ordem lexicografica veremos algo em relacao a essas posicoes
        > - ...aaaaaa_bb 
        > - ...aaaaa_bab
        > - ...aaaaa_bba
        > - ...aaaa_baab
        > - ...aaaa_baba
        > - ...aaaa_bbaa
        > - ...aaa_baaab
        > - ...aaa_baaba
        > - ...aaa_babaa
        > - ...aaa_bbaaa
        > 
        > Com $b_0$ estando em 1 pode ser representada apenas a primeira string.
        >
        > Com $b_1$ estando em 2 podem ser representadas a 2 e 3 string .
        >
        > Com $b_1$ estando em 3 podem ser representadas da 4 ate a 6 string.
        >
        > Com $b_1$ estando em 4 podem ser representadas da 7 ate 10 string.
        > 
        > Fixando a posicao $b_0$ conforme as posicoes de $b_1$ crescem (em [0, $b_0-1$]), a colocacao na ordem aumenta dentro dos intervalos citados acima. Quando os dois b`s ficam lado a lado, significa que o maior numero de classificacao para uma posicao fixa de $b_0$ foi alcancado.
        >
        > Assim achamos a posicao de $b_0$ a partir do intervalo de cada posicao e posicionamos $b_1$ gerando uma exata colocacao. Definindo exatamente esses intervalos, quando $b_0$ esta na posicao $i$, podemos descobrir as colocacoes possiveis usando a soma de gaus do seguinte modo
        >
        > - $ [ (1+i-1)*(i-1)/2 + 1, (i+1)*i/2] $
        >
        > O fim desse intervalo, ou seja, a ultima classificacao que pode ser gerada quando $b_0$ esta em $i$ acaba sendo aprenas a soma da quantidade de strings que puderam ser geradas ate o momento, assim sendo a soma de gaus de 1 ate i
        >
        > O inicio desse intervalo fechado a soma de gaus de 1 ate $i-1$ somado a 1 (ja que a primeira colocacao contida no intervalo associado a posicao $i$ e o a primeira apos o intervalo de $i-1$ )
        >
        > Achando a posicao de $b_0$ devemos agora posicionar $b_1$ da seguinte forma
        >
        >   - $b_1$ pos : k - incio do intervalo
        >
        > No codigo usei busca binaria para achar a posicao de $b_0$ e no final apenas desinverti as posicoes dos dois b`s

    - Codigo
        ```
            #include<iostream>
            using namespace std;

            #define int long long

            int n; 

            int gaus(int i)
            {
                return (1 + i) * i / 2;
            }

            int bb(int k)
            {
                int l = 1, r = n-1;

                while(l < r)
                {
                    int mid = (l+r)/2;

                    if(gaus(mid) == k)
                        return mid;
                    
                    if(gaus(mid) > k)
                        r = mid;
                    else
                        l = mid + 1;
                }

                return l;
            }

            void solve()
            {

                int k; cin >> n >> k;

                int b[2];
                b[0] = bb(k);

                int past = gaus(b[0]-1);

                b[1] = k-past-1;

                b[0] = n - 1 - b[0];
                b[1] = n - 1 - b[1];

                for(int i = 0; i < n; i++ )
                {

                    if(i == b[0] || b[1] == i )
                        cout << 'b';
                    else 
                        cout << 'a';
                }

                cout << endl;

            }

            signed main()
            {
                int t; cin >> t;

                while(t--)
                    solve();

                return 0;
            }
        ```

- Amusement Park Adventure 
    - Ideia
        > So verificar em quais parques a altura dele esta acima da altura minima
    - Codigo
        ```
        #include<iostream>
        using namespace std;

        #define int long long

        void solve()
        {

            int n, h; cin >> n >> h;

            int cont = 0;

            while(n--)
            {
                int aux; cin >> aux;

                if(aux <= h)
                    cont++;
            }

            cout << cont << endl;
        }

        signed main()
        {
            int t = 1; 
            // cin >> t;

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
        > Realmente so simular o que o enunciado diz
    - Codigo
        ```
        #include<bits/stdc++.h>
        using namespace std;

        #define int long long

        void solve()
        {

            int D, C,R; cin >> D >> C >> R;

            int tot = R; // Ele vai sempre conseguir fazer todas as atividades
            // que dao energia a ele entao podemos usar de valor incial

            vector<int> tiring(C);

            for(auto &v: tiring)
                cin >> v;

            // Como ele faz todas as atividades que dao energia
            // apenas as somarei no valor total de energia
            while(R--)
            {
                int aux; cin >> aux;
                D += aux;
            }
            for(auto v: tiring)
            {
                if(v > D)
                    break;
                D-=v;
                tot++;
            }

            cout << tot << endl;
        }

        signed main()
        {
            int t = 1; 
            // cin >> t;

            while(t--)
                solve();

            return 0;
        }
        ```

- Book Shop 
    - Ideia
        > Realmente so simular o que o enunciado diz
    - Codigo
        ```
        #include<bits/stdc++.h>
 
        using namespace std;
        
        int prices[int(1e5)+1];
        int pages[int(1e5)+1];
        int dp[int(1e5)+1];
        
        int n, z;
        
        void solve()
        {
            memset(dp, 0, sizeof(dp));
        
        
            cin >> n >> z;
        
            for(int i = 0; i < n; i++)
                cin >> prices[i];
        
            for(int i = 0; i < n; i++)
                cin >> pages[i];
        
        
            int biggest = 0;
        
            for(int i= 0; i < n; i++)
            {
                for(int x = z; x >=0 ; x--)
                {
                    if(x-prices[i] < 0) continue;
        
                    dp[x] = max(dp[x], dp[x-prices[i]] + pages[i]);
        
                    biggest = max(biggest, dp[x-prices[i]]);
                    biggest = max(dp[x], biggest);
                }
            }
        
            cout << biggest << endl;
        
        }
        
        int main()
        {
            solve();
        
        
            return 0;
        }
        ```
