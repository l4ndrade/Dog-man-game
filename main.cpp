#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"functions.cpp"

char map[MSIZEY][MSIZEX+1]{ // MAPA DO JOGO (# - parede, * - pontos, 0 - vazio)
    "############################",
    "#************##************#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#**************************#",
    "#*####*##*########*##*####*#",
    "#*####*##*########*##*####*#",
    "#******##****##****##******#",
    "######*#####0##0#####*######",
    "00000#*#####0##0#####*#00000",
    "00000#*#####0##0#####*#00000",
    "00000#*#####0##0#####*#00000",
    "######*###00000000###*######",
    "000000*0000######0000*000000",
    "######*###0#0000#0###*######",
    "00000#*###0######0###*#00000",
    "00000#*##0000000000##*#00000",
    "00000#*##0########0##*#00000",
    "######*##0########0##*######",
    "#************##************#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#***##*******00*******##***#",
    "###*##*##*########*##*##*###",
    "###*##*##*########*##*##*###",
    "#******##****##****##******#",
    "#*##########*##*##########*#",
    "#*##########*##*##########*#",
    "#**************************#",
    "############################"
};

char mapdir[MSIZEY][MSIZEX+1]{ // MAPA DE DIREÇÕES (< - esquerda, > - direita, A - cima, V - baixo)
    "############################",
    "#000000000000##000000000000#",
    "#0####0#####0##0#####0####0#",
    "#0####0#####0##0#####0####0#",
    "#0####0#####0##0#####0####0#",
    "#00000000000000000000000000#",
    "#0####0##0########0##0####0#",
    "#0####0##0########0##0####0#",
    "#000000##0000##0000##000000#",
    "######0#####0##0#####0######",
    "00000#0#####0##0#####0#00000",
    "00000#0#####0##0#####0#00000",
    "00000#0#####0##0#####0#00000",
    "######0###V<<00000###0######",
    "0000000000V######00000000000",
    "######0###V#0000#0###0######",
    "00000#0###V######0###0#00000",
    "00000#0##V<00000000##0#00000",
    "00000#0##V########0##0#00000",
    "######0##V########0##0######",
    "#00000000>>>V##000000000000#",
    "#0####0#####V##0#####0####0#",
    "#0####0#####V##0#####0####0#",
    "#000##000000>000000000##000#",
    "###0##0##0########0##0##0###",
    "###0##0##0########0##0##0###",
    "#000000##0000##0000##000000#",
    "#0##########0##0##########0#",
    "#0##########0##0##########0#",
    "#00000000000000000000000000#",
    "############################"
};

char mapbkp[MSIZEY][MSIZEX+1]{ // Backup do mapa do jogo
    "############################",
    "#************##************#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#**************************#",
    "#*####*##*########*##*####*#",
    "#*####*##*########*##*####*#",
    "#******##****##****##******#",
    "######*#####0##0#####*######",
    "00000#*#####0##0#####*#00000",
    "00000#*#####0##0#####*#00000",
    "00000#*#####0##0#####*#00000",
    "######*###00000000###*######",
    "000000*0000######0000*000000",
    "######*###0#0000#0###*######",
    "00000#*###0######0###*#00000",
    "00000#*##0000000000##*#00000",
    "00000#*##0########0##*#00000",
    "######*##0########0##*######",
    "#************##************#",
    "#*####*#####*##*#####*####*#",
    "#*####*#####*##*#####*####*#",
    "#***##*******00*******##***#",
    "###*##*##*########*##*##*###",
    "###*##*##*########*##*##*###",
    "#******##****##****##******#",
    "#*##########*##*##########*#",
    "#*##########*##*##########*#",
    "#**************************#",
    "############################"
};

char mapdirbkp[MSIZEY][MSIZEX+1]{ // Backup do mapa de direções
    "############################",
    "#000000000000##000000000000#",
    "#0####0#####0##0#####0####0#",
    "#0####0#####0##0#####0####0#",
    "#0####0#####0##0#####0####0#",
    "#00000000000000000000000000#",
    "#0####0##0########0##0####0#",
    "#0####0##0########0##0####0#",
    "#000000##0000##0000##000000#",
    "######0#####0##0#####0######",
    "00000#0#####0##0#####0#00000",
    "00000#0#####0##0#####0#00000",
    "00000#0#####0##0#####0#00000",
    "######0###V<<00000###0######",
    "0000000000V######00000000000",
    "######0###V#0000#0###0######",
    "00000#0###V######0###0#00000",
    "00000#0##V<00000000##0#00000",
    "00000#0##V########0##0#00000",
    "######0##V########0##0######",
    "#00000000>>>V##000000000000#",
    "#0####0#####V##0#####0####0#",
    "#0####0#####V##0#####0####0#",
    "#000##000000>000000000##000#",
    "###0##0##0########0##0##0###",
    "###0##0##0########0##0##0###",
    "#000000##0000##0000##000000#",
    "#0##########0##0##########0#",
    "#0##########0##0##########0#",
    "#00000000000000000000000000#",
    "############################"
}; 

int hp = 3; // Número de vidas
int pontos = 0; // Pontuaçãp
bool seeker = false; // Bool para indicar se há um fantasma perseguidor

int main(){

    // RELÓGIOS
    sf::Clock pacman_clock;
    sf::Clock ghost_clock;
    sf::Clock ghsprite_clock;
    sf::Clock scoreclock;
    
    // SORTEIO DA POSIÇÃO DAS PILULAS ESPECIAS
    int rx, ry;
    std::srand(std::time(0));
    for(int i = 0 ; i < 4 ; i ++){
        // Sorteia x e y na matriz
        rx = std::rand() % MSIZEX;
        ry = std::rand() % MSIZEY;        
        if(map[ry][rx] == '*'){ // Se for uam posição válida, coloca uma pilula especial lá
            map[ry][rx] = 's';
        }else // Se não, tenta de novo
            i--;
    }

//-Criação de entidades e sprites------------------------------------

    // PACMAN
    Entity pacman;
    init(pacman, 14, 23);
    pacman.intention = R;
    pacman.move = R;
    pacman.cont = 0;

    if(!pacman.texture.loadFromFile("sprites/dogsprites.png")){
        std::cout << "Erro lendo dogsprites.png\n";
        return 0;
    }
    pacman.sprite.setTexture(pacman.texture);

    // FANTASMAS
        // FANTASMAS 1
    Entity ghost_1;
    init(ghost_1, 15, 15);
    

    if(!ghost_1.texture.loadFromFile("sprites/ghost1.png")){
        std::cout << "Erro lendo ghost1.png\n";
        return 0;
    }
    ghost_1.sprite.setTexture(ghost_1.texture);
    ghost_1.move = U;
    ghost_1.cont = 0;
    ghost_1.statex = 0;

        // FANTASMA 2
    Entity ghost_2;
    init(ghost_2, 14, 15);
    

    if(!ghost_2.texture.loadFromFile("sprites/ghost2.png")){
        std::cout << "Erro lendo ghost2.png\n";
        return 0;
    }
    ghost_2.sprite.setTexture(ghost_2.texture);
    ghost_2.move = U;
    ghost_2.cont = 0;
    ghost_2.statex = 0;
        
        // FANTASMA 3
    Entity ghost_3;
    init(ghost_3, 13, 15);
    

    if(!ghost_3.texture.loadFromFile("sprites/ghost3.png")){
        std::cout << "Erro lendo ghost3.png\n";
        return 0;
    }
    ghost_3.sprite.setTexture(ghost_3.texture);
    ghost_3.move = U;
    ghost_3.cont = 0;
    ghost_3.statex = 0;
        // FANTASMA 4
    Entity ghost_4;
    init(ghost_4, 12, 15);
    

    if(!ghost_4.texture.loadFromFile("sprites/ghost4.png")){
        std::cout << "Erro lendo ghost4.png\n";
        return 0;
    }
    ghost_4.sprite.setTexture(ghost_4.texture);
    ghost_4.move = U;
    ghost_4.cont = 0;
    ghost_4.statex = 0;
    

    // PILULA
    sf::Texture pill_texture;
    sf::Sprite pill_sprite;
    if(!pill_texture.loadFromFile("sprites/pilula.png")){
        std::cout << "Erro lendo pilula.png\n";
        return 0;
    }
    pill_sprite.setTexture(pill_texture);

    // PILULA DO SCORE
    sf::Texture score_texture;
    sf::Sprite score_sprite;
    if(!score_texture.loadFromFile("sprites/pilula2.png")){
        std::cout << "Erro lendo pilula2.png\n";
        return 0;
    }
    score_sprite.setTexture(score_texture);
    score_sprite.setPosition(1522, 32);

    // VIDAS
    sf::Texture hp_texture;
    sf::Sprite hp_sprite;

    if(!hp_texture.loadFromFile("sprites/hp.png")){
        std::cout << "Erro lendo hp.png\n";
        return 0;
    }
    hp_sprite.setTexture(hp_texture);
    hp_sprite.setPosition(30, 950);

    // PONTOS ESPECIAIS
    sf::Texture pp_texture;
    sf::Sprite pp_sprite;
    if(!pp_texture.loadFromFile("sprites/steak.png")){
        std::cout << "Erro lendo steak.png\n";
        return 0;
    }
    pp_sprite.setTexture(pp_texture);
    

    // TEXTO DA PONTUAÇÃO
    sf::Font font; 
    if (!font.loadFromFile("font.ttf")){
        std::cout << "Erro lendo font.ttf\n";
        return 0;
    }
    sf::Text scoretxt;
    scoretxt.setFont(font);
    scoretxt.setCharacterSize(60);
    scoretxt.setFillColor(sf::Color::White);
    std::string placar;

    // TEXTO DO CRONÔMETRO
    sf::Text timetxt;
    timetxt.setFont(font);
    timetxt.setCharacterSize(60);
    timetxt.setFillColor(sf::Color::White);
    int time = 0;
    std::string timer;

    // PLANO DE FUNDO
    sf::Texture bg_texture;
    sf::Sprite bg_sprite;
    if(!bg_texture.loadFromFile("sprites/bg.png")){
        std::cout << "Erro lendo bg.png\n";
        return 0;
    }
    bg_sprite.setTexture(bg_texture);
    bg_sprite.setPosition(512, 0);

    // INICIO
    sf::Texture init_texture;
    sf::Sprite init_sprite;
    if(!init_texture.loadFromFile("sprites/init.png")){
        std::cout << "Erro lendo init.png\n";
        return 0;
    }
    init_sprite.setTexture(init_texture);
    init_sprite.setPosition(0, 0);

    //GAME OVER
    sf::Texture go_texture;
    sf::Sprite go_sprite;
    if(!go_texture.loadFromFile("sprites/gameover.png")){
        std::cout << "Erro lendo gameover.png\n";
        return 0;
    }
    go_sprite.setTexture(go_texture);
    go_sprite.setPosition(0, 0);

    // VITÓRIA
    sf::Texture win_texture;
    sf::Sprite win_sprite;
    if(!win_texture.loadFromFile("sprites/win.png")){
        std::cout << "Erro lendo win.png\n";
        return 0;
    }
    win_sprite.setTexture(win_texture);
    win_sprite.setPosition(0, 0);

//-------------------------------------------------------------------
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pac-Man(TP4)");

    while (window.isOpen()){

        sf::Event event;
        if(hp != 0 && pontos < 300){ // Lê enquanto o jogo não acabou 
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
                        pacman.intention = L;
                    else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                        pacman.intention = R;
                    else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
                        pacman.intention = U;
                    else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                        pacman.intention = D;
                }        
            }
        }


        
        if (scoreclock.getElapsedTime().asSeconds() > 3){ // Após 3 segundos, o jogo começa
            
            if(pacman_clock.getElapsedTime().asMilliseconds() > 200/F){ // MOVIMENTO PACMAN
                pacman_clock.restart();

                if(pacman.cont == 0 || pacman.cont == 2){ // Muda o sprite usado a cada 100ms
                    if (pacman.statex == 3) pacman.statex = 0;
                    else pacman.statex++;
                }

                if(pacman.cont == 0){ // Move o pacman a cada 200ms

                    // Verifica a intenção de movimento e a se é possível se mover naquela direção
                    if (pacman.intention == L && (map[pacman.py][pacman.px-1] != '#'))
                        pacman.move = L;
                    else if (pacman.intention == R && (map[pacman.py][pacman.px+1] != '#'))
                        pacman.move = R;
                    else if (pacman.intention == U && map[pacman.py-1][pacman.px] != '#')
                        pacman.move = U;
                    else if (pacman.intention == D && map[pacman.py+1][pacman.px] != '#')
                        pacman.move = D;   

                    // Coleta as pilulas normais ou especiais
                    if(map[pacman.py][pacman.px] == '*'){
                        map[pacman.py][pacman.px] = '0';
                        pontos++;
                    }else if(map[pacman.py][pacman.px] == 's'){
                        map[pacman.py][pacman.px] = '0';
                        pontos+=15;
                    }

                    switch (pacman.move){ // Deixa um rastro do movimento do pacman (usado pelos fantasmas)
                            case L:
                                if((mapdir[pacman.py][pacman.px-1] != '#'))
                                    mapdir[pacman.py][pacman.px] = '<';
                                break;
                            case R:
                                if((mapdir[pacman.py][pacman.px+1] != '#'))
                                    mapdir[pacman.py][pacman.px] = '>';
                                break;
                            case U:
                                if((mapdir[pacman.py-1][pacman.px] != '#'))
                                    mapdir[pacman.py][pacman.px] = 'A';
                                break;
                            case D:
                                if((mapdir[pacman.py+1][pacman.px] != '#'))
                                    mapdir[pacman.py][pacman.px] = 'V';
                                break;
                    }

                    if(pacman.px == ghost_1.px && pacman.py == ghost_1.py || pacman.px == ghost_2.px && pacman.py == ghost_2.py || pacman.px == ghost_3.px && pacman.py == ghost_3.py || pacman.px == ghost_4.px && pacman.py == ghost_4.py){ // Verifica se o pacman foi pego antes de se movimentar
                        hp--; // Tira 1 vida
                        ghost_1.mtype = RM; // Coloca todos os fantasmas para se mover aleatoriamnete
                        ghost_2.mtype = RM;
                        ghost_3.mtype = RM;
                        ghost_4.mtype = RM;
                        seeker = false; // Identifica que não existe mais um fantasmas perseguidor
                        movetoorigin(pacman); // Coloca o pacman na sua posição original
                        pacman.intention = R;
                        pacman.move = R;
                        // Reinicia a matriz de direções
                        for(int i = 0 ; i < MSIZEY ; i++)
                            for(int j = 0 ; j < MSIZEX ; j++)
                                if(mapdir[i][j] != '#')
                                    mapdir[i][j] = '0';
                    }

                    moveobj(pacman, map); // Muda px e py do pacman;
                
                }

                movesprite(pacman); // Move o sprite do pacman 32/F px
                
                
                pacman.cont++;

                if(pacman.cont == 0){ // Verifica se  o pacman foi pego após se mover
                    if(pacman.px == ghost_1.px && pacman.py == ghost_1.py || pacman.px == ghost_2.px && pacman.py == ghost_2.py || pacman.px == ghost_3.px && pacman.py == ghost_3.py || pacman.px == ghost_4.px && pacman.py == ghost_4.py){
                        hp--;
                        ghost_1.mtype = RM;
                        ghost_2.mtype = RM;
                        ghost_3.mtype = RM;
                        ghost_4.mtype = RM;
                        seeker = false;
                        movetoorigin(pacman);
                        pacman.intention = R;
                        pacman.move = R;

                        for(int i = 0 ; i < MSIZEY ; i++)
                            for(int j = 0 ; j < MSIZEX ; j++)
                                if(mapdir[i][j] != '#')
                                    mapdir[i][j] = '0';
                    }
                }

                if (pacman.cont == F) pacman.cont = 0; // Reincia o contador do pacman

            }

            if((ghost_clock.getElapsedTime()).asMilliseconds() > 204/F){ // MOVIMENTO FANTASMA
                ghost_clock.restart();

                
                if(ghost_1.cont == 0){

                    if(pacman.cont == 0){ // Verifica se o pacman foi pego depois dos fantasmas se moverem
                        if(pacman.px == ghost_1.px && pacman.py == ghost_1.py || pacman.px == ghost_2.px && pacman.py == ghost_2.py || pacman.px == ghost_3.px && pacman.py == ghost_3.py || pacman.px == ghost_4.px && pacman.py == ghost_4.py){
                            hp--;
                            ghost_1.mtype = RM;
                            ghost_2.mtype = RM;
                            ghost_3.mtype = RM;
                            ghost_4.mtype = RM;
                            seeker = false;
                            movetoorigin(pacman);
                            pacman.intention = R;
                            pacman.move = R;

                            for(int i = 0 ; i < MSIZEY ; i++)
                                for(int j = 0 ; j < MSIZEX ; j++)
                                    if(mapdir[i][j] != '#')
                                        mapdir[i][j] = '0';
                        }
                    }

                    // FANTASMA 1
                    if(ghost_1.mtype == RM){ // Se o tipo de movimento for aleatório
                        if((mapdir[ghost_1.py][ghost_1.px] == '>' || mapdir[ghost_1.py][ghost_1.px] == '<' || mapdir[ghost_1.py][ghost_1.px] == 'A' || mapdir[ghost_1.py][ghost_1.px] == 'V') && !seeker){ // Verifica se encontrou o rastro do pacman e se ja há um fantasma perseguidor
                            seeker = true; // Identifica que já existe um fantasma do tipo perseguidor no jogo
                            ghost_1.mtype = PM; // Muda o tipo de movimento para pereguidor
                            persdir(ghost_1, mapdir); // Executa seleção de direção por perseguição
                        }else
                            randomdir(ghost_1, map); // Executa seleção de direção aleatório
                        moveobj(ghost_1, map); // Move o fantasma baseado na direção estabelecida
                    }
                    else if(ghost_1.mtype == MA){ // Se o tipo de movimnto for desregrado
                        ghost_1.move = U; // Escolhe se mover pra cima
                        moveanyway(ghost_1, map); // Se move desregradamente
                        if(ghost_1.py == ghost_1.oy-2) ghost_1.mtype = RM; // Se já saiu da área de movimento desregrado, muda para movimento aleatório
                    }else{ // Se o movimento já é de perseguição
                        persdir(ghost_1, mapdir); // Executa seleção de direção por perseguição
                        moveobj(ghost_1, map); // Move o fantasma
                    }
                    // FANTASMA 2
                    if(ghost_2.mtype == RM){
                        if((mapdir[ghost_2.py][ghost_2.px] == '>' || mapdir[ghost_2.py][ghost_2.px] == '<' || mapdir[ghost_2.py][ghost_2.px] == 'A' || mapdir[ghost_2.py][ghost_2.px] == 'V') && !seeker){
                            seeker = true;
                            ghost_2.mtype = PM;
                            persdir(ghost_2, mapdir);
                        }else
                            randomdir(ghost_2, map);
                        moveobj(ghost_2, map);
                    }
                    else if(ghost_2.mtype == MA){
                        ghost_2.move = U;
                        moveanyway(ghost_2, map);
                        if(ghost_2.py == ghost_2.oy-2) ghost_2.mtype = RM;
                    }else{
                        persdir(ghost_2, mapdir);
                        moveobj(ghost_2, map);
                    }
                    // FANTASMA 3
                    if(ghost_3.mtype == RM){
                        if((mapdir[ghost_3.py][ghost_3.px] == '>' || mapdir[ghost_3.py][ghost_3.px] == '<' || mapdir[ghost_3.py][ghost_3.px] == 'A' || mapdir[ghost_3.py][ghost_3.px] == 'V') && !seeker){
                            seeker = true;
                            ghost_3.mtype = PM;
                            persdir(ghost_3, mapdir);
                        }else
                            randomdir(ghost_3, map);
                        moveobj(ghost_3, map);
                    }
                    else if(ghost_3.mtype == MA){
                        ghost_3.move = U;
                        moveanyway(ghost_3, map);
                        if(ghost_3.py == ghost_3.oy-2) ghost_3.mtype = RM;
                    }else{
                        persdir(ghost_3, mapdir);
                        moveobj(ghost_3, map);
                    }
                    // FANTASMA 4
                    if(ghost_4.mtype == RM){
                        if((mapdir[ghost_4.py][ghost_4.px] == '>' || mapdir[ghost_4.py][ghost_4.px] == '<' || mapdir[ghost_4.py][ghost_4.px] == 'A' || mapdir[ghost_4.py][ghost_4.px] == 'V') && !seeker){
                            seeker = true;
                            ghost_4.mtype = PM;
                            persdir(ghost_4, mapdir);
                        }else
                            randomdir(ghost_4, map);
                        moveobj(ghost_4, map);
                    }
                    else if(ghost_4.mtype == MA){
                        ghost_4.move = U;
                        moveanyway(ghost_4, map);
                        if(ghost_4.py == ghost_4.oy-2) ghost_4.mtype = RM;
                    }else{
                        persdir(ghost_4, mapdir);
                        moveobj(ghost_4, map);
                    }

                    if(pacman.cont == 0){ // Verifica se o pacman foi pego depois dos fantasmas se moverem
                        if(pacman.px == ghost_1.px && pacman.py == ghost_1.py || pacman.px == ghost_2.px && pacman.py == ghost_2.py || pacman.px == ghost_3.px && pacman.py == ghost_3.py || pacman.px == ghost_4.px && pacman.py == ghost_4.py){
                            hp--;
                            ghost_1.mtype = RM;
                            ghost_2.mtype = RM;
                            ghost_3.mtype = RM;
                            ghost_4.mtype = RM;
                            seeker = false;
                            movetoorigin(pacman);
                            pacman.intention = R;
                            pacman.move = R;

                            for(int i = 0 ; i < MSIZEY ; i++)
                                for(int j = 0 ; j < MSIZEX ; j++)
                                    if(mapdir[i][j] != '#')
                                        mapdir[i][j] = '0';
                        }
                    }
                        
                }
                // Move os sprites dos fantasmas
                movesprite(ghost_1);
                movesprite(ghost_2);
                movesprite(ghost_3);
                movesprite(ghost_4);
                ghost_1.cont++;

                if (ghost_1.cont == F) ghost_1.cont = 0; // Reinicia o contador dos fantasmas                
            }
        }    
            
            if(hp == 0 || pontos >= 300){ // Verifica se ganhou ou perdeu

                // Prende todas as entidades nas suas posições atuais
                map[pacman.py+1][pacman.px] = '#';
                map[pacman.py-1][pacman.px] = '#';
                map[pacman.py][pacman.px+1] = '#';
                map[pacman.py][pacman.px-1] = '#';
                
                map[ghost_1.py+1][ghost_1.px] = '#';
                map[ghost_1.py-1][ghost_1.px] = '#';
                map[ghost_1.py][ghost_1.px+1] = '#';
                map[ghost_1.py][ghost_1.px-1] = '#';

                map[ghost_2.py+1][ghost_2.px] = '#';
                map[ghost_2.py-1][ghost_2.px] = '#';
                map[ghost_2.py][ghost_2.px+1] = '#';
                map[ghost_2.py][ghost_2.px-1] = '#';

                map[ghost_3.py+1][ghost_3.px] = '#';
                map[ghost_3.py-1][ghost_3.px] = '#';
                map[ghost_3.py][ghost_3.px+1] = '#';
                map[ghost_3.py][ghost_3.px-1] = '#';

                map[ghost_4.py+1][ghost_4.px] = '#';
                map[ghost_4.py-1][ghost_4.px] = '#';
                map[ghost_4.py][ghost_4.px+1] = '#';
                map[ghost_4.py][ghost_4.px-1] = '#';

            
                while (window.pollEvent(event)){ // Lê input para reiniciar ou fechar o jogo
                    if (event.type == sf::Event::Closed)
                        window.close();

                    else if (event.type == sf::Event::KeyPressed){ // Reinicia variáveis
                        if(event.key.code == sf::Keyboard::Enter){
                            for(int i = 0 ; i < MSIZEY ; i++)
                                for(int j = 0 ; j < MSIZEX ; j++){
                                    map[i][j] = mapbkp[i][j];
                                    mapdir[i][j] = mapdirbkp[i][j];
                                }

                            for(int i = 0 ; i < 4 ; i ++){
                                rx = std::rand() % MSIZEX;
                                ry = std::rand() % MSIZEY;        
                                if(map[ry][rx] == '*'){
                                    map[ry][rx] = 's';
                                }else
                                    i--;
                            }

                            init(ghost_1, 15, 15);
                            ghost_1.move = U;
                            ghost_1.cont = 0;
                            ghost_1.statex = 0;
                            init(ghost_2, 14, 15);
                            ghost_2.move = U;
                            ghost_2.cont = 0;
                            ghost_2.statex = 0;
                            init(ghost_3, 13, 15);
                            ghost_4.move = U;
                            ghost_3.cont = 0;
                            ghost_3.statex = 0;
                            init(ghost_4, 12, 15);
                            ghost_4.move = U;
                            ghost_4.cont = 0;
                            ghost_4.statex = 0;
                                    
                            init(pacman, 14, 23);
                            pacman.intention = R;
                            pacman.move = R;
                            pacman.cont = 0;

                            hp = 3;
                            pontos = 0;
                            seeker = false;
                            scoreclock.restart();

                        }  
                        else if(event.key.code == sf::Keyboard::Escape)
                            window.close();
                    }
                }
            }

            sf::IntRect pacmanrect(pacman.statex*CSIZE, pacman.move*CSIZE, CSIZE, CSIZE); // Retangulo que define sprite do pacman
            pacman.sprite.setTextureRect(pacmanrect);

            sf::IntRect hprect(0, 0, 64 * hp, 64); // Retangulo que define hp do pacman
            hp_sprite.setTextureRect(hprect);

            // Define o sprite baseado no tipo de movimento dos fantasmas
            if(ghost_1.mtype == PM)
                ghost_1.statex = 1;
            else
                ghost_1.statex = 0;
            if(ghost_2.mtype == PM)
                ghost_2.statex = 1;
            else
                ghost_2.statex = 0;
            if(ghost_3.mtype == PM)
                ghost_3.statex = 1;
            else
                ghost_3.statex = 0;
            if(ghost_4.mtype == PM)
                ghost_4.statex = 1;
            else
                ghost_4.statex = 0;
            
            sf::IntRect g1rect(ghost_1.statex*CSIZE, ghost_1.move*CSIZE, CSIZE, CSIZE);
            ghost_1.sprite.setTextureRect(g1rect);
            sf::IntRect g2rect(ghost_2.statex*CSIZE, ghost_2.move*CSIZE, CSIZE, CSIZE);
            ghost_2.sprite.setTextureRect(g2rect);
            sf::IntRect g3rect(ghost_3.statex*CSIZE, ghost_3.move*CSIZE, CSIZE, CSIZE);
            ghost_3.sprite.setTextureRect(g3rect);
            sf::IntRect g4rect(ghost_4.statex*CSIZE, ghost_4.move*CSIZE, CSIZE, CSIZE);
            ghost_4.sprite.setTextureRect(g4rect);

            // Configura string que mostra pontos
            placar = "Ossos: " + std::to_string(pontos);
            scoretxt.setString(placar);
            scoretxt.setPosition(1590, 20);

            time = (scoreclock.getElapsedTime().asMilliseconds());
            if(time>=2999 && hp > 0 && pontos < 300){ // Conta o tempo e configura string do tempo assim que os 3 segundos de espera iniciais acabam
                timer = "Tempo: " + std::to_string((time-3000)/1000) + "." + std::to_string(((time-3000)%1000)/100);
                timetxt.setPosition(1590, 80);
                timetxt.setCharacterSize(60);
            }
            else if(hp > 0 && pontos < 300){ // Se o jogo ainda não começou
                timer = std::to_string((4000-time)/1000) + "...";
                timetxt.setPosition(860, 450);
                timetxt.setCharacterSize(200);
            }else{
                timetxt.setPosition(1590, 80);
                timetxt.setCharacterSize(60);
            }
            timetxt.setString(timer);
            
        

        //------------------------------------------------------------------------------------------------------------------

        
        window.clear(sf::Color::Black);
        

        // CONSTRUÇÃO DO MAPA
        window.draw(bg_sprite);
        for (int i = 0 ; i < MSIZEX ; i++)
            for (int j = 0 ; j < MSIZEY ; j++)
                if (map[j][i] == '*'){
                    pill_sprite.setPosition(512+i*CSIZE, j*CSIZE);
                    window.draw(pill_sprite);
                }else if(map[j][i] == 's'){
                    pp_sprite.setPosition(512+i*CSIZE, j*CSIZE);
                    window.draw(pp_sprite);
                }
        
        if(time >=3000){ // Desenha as entidades apenas quando o jogo começa
            window.draw(pacman.sprite);
            window.draw(ghost_1.sprite);
            window.draw(ghost_2.sprite);
            window.draw(ghost_3.sprite);
            window.draw(ghost_4.sprite);
        }else // Se não começou, desenha tela de inicio
            window.draw(init_sprite);
        
        if(hp == 0) // Se perdeu, desenha a tela de game over
            window.draw(go_sprite);

        if(pontos >= 300) // Se ganhou, desenha a tela de vitória
            window.draw(win_sprite);

        window.draw(timetxt);

        if(time>=3000){ // Se o jogo já começou, desenha os textos
            window.draw(scoretxt);
            window.draw(score_sprite);
            window.draw(hp_sprite);
        }
        window.display();
    }
    
    return 0;
}