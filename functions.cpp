#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

const int CSIZE = 32; // Tamanho de uma célula
const int F = 4; // Fluidez da animação (só aceita os valores: 1, 2, 4, 8)

const int MSIZEY = 31; // Número de linhas do maoa
const int MSIZEX = 28; // Número de colunas do mapa

enum direcao{R, L, U, D}; // Direções de movimento
enum movtype{RM, MA, PM}; // Tipos de movimentação do fantasma (aleatório, desregrado e de perseguição)
struct Entity{ // Estrutura organizada dos dados de uma entidade

    int px, py; // Posição
    int dx, dy; // Posição do desenho
    int ox, oy; // Posições de origem
    sf::Texture texture; // Textura
    sf::Sprite sprite; // Sprite
    int statex, statey; // Controle de sprites
    direcao move; // Direção de movimento
    direcao intention; // Intenção de movimento
    int cont; // Controle de sprites e movimentação
    bool moved; // Auxiliar de movimentação
    movtype mtype; // Auxilar que indica que tipo de movimentação será usada pelo fantasma
};


void moveobj(Entity &obj, char map[MSIZEY][MSIZEX+1]){ // Verifica o movimento atual e move o objeto, se for posível

    if (obj.move == L && (map[obj.py][obj.px-1] != '#')){
        obj.px--;
        obj.moved = true;
        if (obj.px < 0){ // Se saiu do mapa
            obj.px = MSIZEX-1;
            obj.dx = (MSIZEX)*CSIZE;
        }
    }else if (obj.move == R && (map[obj.py][obj.px+1] != '#')){
        obj.px++;
        obj.moved = true;
        if (obj.px > MSIZEX-1){ // Se saiu do mapa
            obj.px = 0;
            obj.dx = -CSIZE;
        }
    }else if (obj.move == U && map[obj.py-1][obj.px] != '#'){
        obj.py--;
        obj.moved = true;
    }else if (obj.move == D && map[obj.py+1][obj.px] != '#'){
        obj.py++;
        obj.moved = true;
    }else
        obj.moved = false;

}

void moveanyway(Entity &obj, char map[MSIZEY][MSIZEX+1]){ // Move o objeto independente de paredes
     if (obj.move == L){
        obj.px--;
        obj.moved = true;
        if (obj.px < 0){
            obj.px = MSIZEX-1;
            obj.dx = (MSIZEX)*CSIZE;
        }
    }else if (obj.move == R){
        obj.px++;
        obj.moved = true;
        if (obj.px > MSIZEX-1){
            obj.px = 0;
            obj.dx = -CSIZE;
        }
    }else if (obj.move == U){
        obj.py--;
        obj.moved = true;
    }else if (obj.move == D){
        obj.py++;
        obj.moved = true;
    }else
        obj.moved = false;
}

void movesprite(Entity &obj){ // Move o sprite do objeto sem alterar a sua real posição
    if (obj.move == L && obj.moved)
        obj.dx -= CSIZE/F;
    else if (obj.move == R && obj.moved)
        obj.dx += CSIZE/F;
    else if (obj.move == U && obj.moved)
        obj.dy -= CSIZE/F;
    else if (obj.move == D && obj.moved)
        obj.dy += CSIZE/F;
    
    obj.sprite.setPosition(512 + obj.dx, obj.dy);
}

void init(Entity &obj, int px, int py){ // Inicializa as vatiáveis do objeto

    obj.px = px;
    obj.py = py;
    obj.ox = px;
    obj.oy = py;
    obj.dx = obj.px * CSIZE;
    obj.dy = obj.py * CSIZE;
    obj.cont = 0;
    obj.moved = false;
    obj.statex = 0;
    obj.statey = 0;
    obj.mtype = MA;

}

void movetoorigin(Entity &obj){ // Teleporta o objeto para a sua posição de origem
    obj.px = obj.ox;
    obj.py = obj.oy;
    obj.dx = obj.px * CSIZE;
    obj.dy = obj.py * CSIZE;
}

void randomdir(Entity &obj, char map[MSIZEY][MSIZEX+1]){ // Seleciona uma direção aleatória para se mover
    int aux;
    switch (obj.move){
        case L: 
            if(map[obj.py+1][obj.px] != '#' || map[obj.py-1][obj.px] != '#' || map[obj.py][obj.px-1] != '#'){ // Verifica as possíveis direções de moviemnto (ignorando a contrária à atual, para que ele não se mova para trás)
                while (true){

                    aux = std::rand() % 3; // Sorteia a direção

                    if(aux == 0 && map[obj.py-1][obj.px] != '#'){ // Se puder, vai para cima
                        obj.move = U;
                        break;
                    }else if(aux == 1 && map[obj.py+1][obj.px] != '#'){ // Se puder, vai para baixo
                        obj.move = D;
                        break;
                    }else // Continua para a esquerda
                        break; 
                }
            }
            break;
        case R:
            if(map[obj.py+1][obj.px] != '#' || map[obj.py-1][obj.px] != '#' || map[obj.py][obj.px+1] != '#'){
                aux = std::rand() % 3;
                
                if(aux == 0 && map[obj.py-1][obj.px] != '#'){ // Se puder, vai para cima
                    obj.move = U;
                    break;
                }else if(aux == 1 && map[obj.py+1][obj.px] != '#'){ // Se puder, vai para baixo
                    obj.move = D;
                    break;
                }else // Continua para a direita
                    break; 
            }
            break;
        case U:
            if(map[obj.py-1][obj.px] != '#' || map[obj.py][obj.px-1] != '#' || map[obj.py][obj.px+1] != '#'){
                aux = std::rand() % 3;
                
                if(aux == 0 && map[obj.py][obj.px+1] != '#'){ // Se puder, vai para a direita
                    obj.move = R;
                    break;
                }else if(aux == 1 && map[obj.py][obj.px-1] != '#'){ // Se puder, vai para a esquerda
                    obj.move = L;
                    break;
                }else // Continua para a cima
                    break; 
            }
            break;
        case D:
            if(map[obj.py+1][obj.px] != '#' || map[obj.py][obj.px-1] != '#' || map[obj.py][obj.px+1] != '#'){
                aux = std::rand() % 3;
                
                if(aux == 0 && map[obj.py][obj.px+1] != '#'){ // Se puder, vai para a direita
                    obj.move = R;
                    break;
                }else if(aux == 1 && map[obj.py][obj.px-1] != '#'){ // Se puder, vai para a esquerda
                    obj.move = L;
                    break;
                }else // Continua para a baixo
                    break; 
            }
            break;
    }
}

void persdir(Entity &obj, char mapdir[MSIZEY][MSIZEX+1]){ // Seleciona a direção de acordo com o rastro deixado no na matriz
    switch (mapdir[obj.py][obj.px]){
        case '>':
            obj.move = R;
            break;
        case '<':
            obj.move = L;
            break;
        case 'A':
            obj.move = U;
            break;
        case 'V':
            obj.move = D;
            break;
    }
}