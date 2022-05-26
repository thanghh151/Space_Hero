#include"CommonFunc.h"

//threats
int multiply[SCREEN_WIDTH];
SDL_Rect pos[SCREEN_WIDTH];

//player
int lives = NUM_LIVES;

//bullet
class bullet
{
	public:
        void init();
        void render();
        void destroy();
        SDL_Rect bullet;

    	private:
        int xpos , ypos;

};

void bullet::render()
{
	bullet.h = 10;
	bullet.w = 5;
	bullet.y -= 6;

	g_bullet_img = SDL_LoadBMP("img/bullet.bmp");
	if(g_bullet_img == NULL){
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
	}

	g_bullet_tex = SDL_CreateTextureFromSurface(g_renderer, g_bullet_img);
	SDL_FreeSurface(g_bullet_img);
	if(g_bullet_tex == NULL)
   	{
		SDL_GetError();
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
	}

 	SDL_RenderCopy(g_renderer, g_bullet_tex, NULL,&bullet);
}

int random_threats(int x, int rand ,SDL_Rect p , bullet B[])
{
	if(rand==2)
    	{
		multiply[x]=1;
	    	pos[x].x = x;
	}
	for(int i = 0; i < (SCREEN_WIDTH-50); i++)
	{
		if(multiply[i] == 1)
        {
			SDL_RenderCopy(g_renderer, g_threat_tex, NULL, &pos[i]);
	    		pos[i].y+=2.5;

	    //threats gone
	    if(pos[i].y >= SCREEN_HEIGHT)
            {
	       multiply[i] = 0;
	       pos[i].y = 0;
	       lives--;
	    }
	    if(p.y >= (pos[i].y-p.h) && p.y <= (pos[i].y + pos[i].h))
            {
            if(p.x <= (pos[i].x + pos[i].w) && p.x >= pos[i].x)
            {
                multiply[i] = 0;
                pos[i].y = 0;
                lives--;
            }
            if((p.x + p.w) <= (pos[i].x + pos[i].w) && (p.x + p.w) >= pos[i].x)
            {
                multiply[i] = 0;
                pos[i].y = 0;
                lives--;
            }
	    }
        if(p.x >= (pos[i].x + p.x) && p.x <= (pos[i].x + pos[i].w))
        {
            if(p.y <= (pos[i].y + pos[i].h) && p.y >= pos[i].y)
            {
                multiply[i] = 0;
                pos[i].y = 0;
                lives--;
            }
            if((p.y + p.h)<=(pos[i].y + pos[i].h) && (p.y + p.h) >= pos[i].y)
            {
                multiply[i] = 0;
                pos[i].y = 0;
                lives--;
            }
	    }
	    for(int j = 0; j < NUM_BULLETS; j++)
        {
            if(B[j].bullet.x >= pos[i].x && (B[j].bullet.x + B[j].bullet.w) <= (pos[i].x + pos[i].w))
            {
                if(B[j].bullet.y <= (pos[i].y + pos[i].h))
                {
                    multiply[i] = 0;
                    B[j].bullet.x = SCREEN_WIDTH + 100;
                    B[j].bullet.y = SCREEN_HEIGHT + 1000000;
                }
            }
	    }
        }
	}
}

void fps_optimize(Uint32 starting_tick)
{
	if((1000 / FPS) > SDL_GetTicks() - starting_tick)
    {
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
	}
}

void close()
{
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    while(true){
        if(SDL_WaitEvent(&g_event) != 0 && (g_event.type == SDL_KEYDOWN || g_event.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char* argv[])
{
    int currentscore;
	//multiply threats randomly
	for(int i = 0; i < (SCREEN_WIDTH - 50); i++)
        {
		pos[i].w=50;
		pos[i].h=60;
	}
	memset(multiply,0,sizeof(multiply[0])*1000);
	//initializing graphics and timer system
	if(SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER)!=0)
	{
		return 1;
	}

	//creating a Window
	g_window = SDL_CreateWindow("UET-Game",
				    SDL_WINDOWPOS_CENTERED,
				    SDL_WINDOWPOS_CENTERED,
				    SCREEN_WIDTH, SCREEN_HEIGHT,
				    SDL_WINDOW_RESIZABLE);
	if(g_window == NULL)
    	{
		SDL_Quit();
		return 1;
	}

	//creating a renderer
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	g_renderer = SDL_CreateRenderer(g_window, -1, render_flags);
	if(g_renderer == NULL)
    	{
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	//loading background
	SDL_RenderPresent(g_renderer);
	SDL_Delay(1500);
	Uint32 starting_tick;

    	g_background = SDL_LoadBMP("img/background.bmp");
	if(g_background == NULL)
    	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	g_background_tex = SDL_CreateTextureFromSurface(g_renderer, g_background);
	SDL_FreeSurface(g_background);
	if(g_background_tex == NULL)
    	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	//loading player
    	g_player = SDL_LoadBMP("img/player.bmp");
	if(g_player == NULL)
	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	g_player_tex = SDL_CreateTextureFromSurface(g_renderer, g_player);
	SDL_FreeSurface(g_player);
	if(g_player_tex == NULL)
    	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	//loading threats
	g_threat = SDL_LoadBMP("img/threat.bmp");
	if(g_threat == NULL)
    	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	g_threat_tex = SDL_CreateTextureFromSurface(g_renderer, g_threat);
	SDL_FreeSurface(g_threat);
	if(g_threat_tex == NULL)
    	{
		SDL_DestroyRenderer(g_renderer);
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		return 1;
	}

	//position player
	SDL_Rect p_pos;

	//size of player
	SDL_QueryTexture(g_player_tex, NULL, NULL, &p_pos.w, &p_pos.h);
	p_pos.w;
	p_pos.h;

 	//start player on screen
 	float x_pos = (SCREEN_WIDTH - p_pos.w) / 2;
 	float y_pos = (SCREEN_HEIGHT - p_pos.h);
 	float x_vel = 0;
 	float y_vel = 0;

 	int up = 0;
 	int down = 0;
 	int left = 0;
 	int right = 0;
    SDL_Rect life;


    g_load = SDL_LoadBMP("img/loading.bmp");
    g_load_tex = SDL_CreateTextureFromSurface(g_renderer, g_load);
    SDL_FreeSurface(g_load);
    SDL_RenderCopy(g_renderer, g_load_tex, NULL, NULL);
    SDL_RenderPresent(g_renderer);
    SDL_Delay(10000);

    bullet B[NUM_BULLETS];
    int initial = 0;
    int time = 0;

    SDL_Event event;
    bool running = true;
    while(running){
    if(lives==0)
    {
        g_gameover_img = SDL_LoadBMP("img/gameover.bmp");
        g_gameover_tex = SDL_CreateTextureFromSurface(g_renderer, g_gameover_img);
        SDL_FreeSurface(g_gameover_img);
        SDL_RenderCopy(g_renderer, g_gameover_tex, NULL, NULL);
        SDL_RenderPresent(g_renderer);
        SDL_Delay(2000);
    }
        currentscore = SDL_GetTicks()/1000;
        while(SDL_PollEvent(&event))
        {
        //initializing bullet
            if(event.key.keysym.scancode == SDL_SCANCODE_SPACE && event.key.repeat == 0)
            {
            time++;
            if(time>1)
            {
                initial++;
                if(initial>=NUM_BULLETS)
                    {
                        initial=0;
                    }
                        B[initial].bullet.x = x_pos + p_pos.w/2 -2;
                        B[initial].bullet.y = y_pos;
                        time =0;
            }
            }
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode){
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            up = 1;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            left = 1;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            down = 1;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            right = 1;
                            break;
 						}
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.scancode){
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            up = 0;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            left = 0;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            down = 0;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            right = 0;
                            break;
 					}
                break;
            }
        }
        //Velocity
        x_vel = 0;
        y_vel = 0;
        if(up && !down) y_vel = -SPEED;
        if(down && !up) y_vel = SPEED;
        if(left && !right) x_vel = -SPEED;
        if(right && !left) x_vel = SPEED;

        //update position
        x_pos += x_vel/60;
        y_pos += y_vel/60;

        //collision with screen
        if(x_pos <= 0) x_pos = 0;
        if(y_pos <= 0) y_pos = 0;
        if(x_pos >= SCREEN_WIDTH - p_pos.w) x_pos = SCREEN_WIDTH - p_pos.w;
        if(y_pos >= SCREEN_HEIGHT - p_pos.h) y_pos = SCREEN_HEIGHT - p_pos.h;

        //set position in structure
        p_pos.y = (int) y_pos;
        p_pos.x = (int) x_pos;

        //clear the Window
        SDL_RenderClear(g_renderer);

        //draw background
        SDL_RenderCopy(g_renderer, g_background_tex, NULL, NULL);

        //draw bullets
        for(int start = 0; start <= initial; start++)
        {
 				if(B[start].bullet.y>0)
 				B[start].render();
        }

        //draw player
        SDL_RenderCopy(g_renderer, g_player_tex, NULL, &p_pos);

        //draw threats
        int x = rand() % (SCREEN_WIDTH-50);
        int p = rand() % 60;
        random_threats(x ,p , p_pos, B);

        SDL_Delay(1000 / FPS);

        //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

        if(lives > 0)
        {
            life.x = 100;
            life.y = 50;
            life.w = 50;
            life.h = 50;
            g_life_img = SDL_LoadBMP("img/life.bmp");
            g_life_tex = SDL_CreateTextureFromSurface(g_renderer, g_life_img);
            SDL_FreeSurface(g_life_img);
            SDL_RenderCopy(g_renderer, g_life_tex, NULL, &life);
            //Mix_LoadMUS("Audio/song.mp3");
        }
        if(lives > 1)
        {
            life.x = 160;
            g_life_img = SDL_LoadBMP("img/life.bmp");
            g_life_tex = SDL_CreateTextureFromSurface(g_renderer, g_life_img);
            SDL_FreeSurface(g_life_img);
            SDL_RenderCopy(g_renderer, g_life_tex, NULL, &life);
        }
        if(lives > 2)
        {
            life.x = 220;
            g_life_img = SDL_LoadBMP("img/life.bmp");
            g_life_tex = SDL_CreateTextureFromSurface(g_renderer, g_life_img);
            SDL_FreeSurface(g_life_img);
            SDL_RenderCopy(g_renderer, g_life_tex, NULL, &life);
        }
        SDL_RenderPresent(g_renderer);

        //optimizing
        fps_optimize(starting_tick);
 		}
 		if(lives == 0)
        {
 		cout << "Score : "<< currentscore << endl;
        }
    waitUntilKeyPressed();
    close();
}
