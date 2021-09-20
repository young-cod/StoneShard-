//#include "stdafx.h"
//#include "rayCast.h"
//
//HRESULT rayCast::init()
//{
//	for (int i = 0; i < TILETESTY; i++)
//	{
//		for (int j = 0; j < TILETESTX; j++)
//		{
//			SetRect(&_tile[i].rc,
//				j*TSIZE,
//				i*TSIZE,
//				j*TSIZE + TSIZE,
//				i*TSIZE + TSIZE);
//
//			//if(i==0)
//		}
//	}
//
//	for (int i = 0; i < TILETESTY; ++i)
//	{
//		for (int j = 0; j < TILETESTX; ++j)
//		{
//			SetRect(&_tile[i*TILETESTX + j].rc,
//				j * TSIZE,
//				i * TSIZE,
//				j * TSIZE + TSIZE,
//				i * TSIZE + TSIZE);
//
//			if (i == 0 || i == TILETESTY - 1)_tile[i*TILETESTX + j].attribute = WALL;
//			else if (j == 0 || j == TILETESTX - 1)_tile[i*TILETESTX + j].attribute = WALL;
//			else
//			{
//				if (95 < RND->getFromIntTo(10, 100))
//				{
//					_tile[i*TILETESTX + j].attribute = WALL;
//				}
//			}
//		}
//	}
//	_player.x = WINSIZEX / 2;
//	_player.y = WINSIZEY / 2;
//
//	_player.rc = RectMakeCenter(_player.x, _player.y, TSIZE, TSIZE);
//
//	_player.angle = 1;
//
//	rx = ry = 0;
//
//	ho = false;
//	ver = false;
//	return S_OK;
//}
//
//void rayCast::release()
//{
//}
//
//void rayCast::update()
//{
//	test();
//}
//
//void rayCast::test()
//{
//	//if (KEYMANAGER->isStayKeyDown('A'))_player.angle -= RD;
//	//if (KEYMANAGER->isStayKeyDown('D'))_player.angle += RD;
//
//	//cout << _player.angle << endl;
//	//if (_player.angle < 0) { _player.angle += 2 * PI; }
//	//if (_player.angle > 2 * PI) { _player.angle -= 2 * PI; }
//	//_player.rc = RectMakeCenter(_player.x, _player.y, 10, 10);
//
//	//ra = _player.angle - RD * VULSIZE;
//	//if (ra < 0) { ra += 2 * PI; }
//	//if (ra > 2 * PI) { ra -= 2 * PI; }
//	//_player.x = _ptMouse.x;
//	//_player.y = _ptMouse.y;
//
//	//s.x = _player.x;
//	//s.y = _player.y;
//	//for (int i = 0; i < VULSIZE; ++i)
//	//{
//	//	dof = 0;
//	//	float distH = TSIZE * TLENTH, hx = _player.x, hy = _player.y;
//	//	float aTan = -1 / tan(ra);
//
//	//	if (ra >= PI) { ry = (((int)_player.y / TSIZE) * TSIZE) - 0.0001;	rx = _player.x + (_player.y - ry)*aTan; yo = -TSIZE; xo = -yo * aTan; }
//	//	if (ra <= PI) { ry = ((int)(_player.y / TSIZE) + 1)		 * TSIZE;	rx = _player.x + (_player.y - ry)*aTan; yo = TSIZE; xo = -yo * aTan; }
//	//	if (ra == 0 || ra == PI) { rx = _player.x; ry = _player.y; dof = TLENTH; }
//
//	//	while (dof < TLENTH)
//	//	{
//
//	//		mx = (int)(rx) / TSIZE;
//	//		my = (int)(ry) / TSIZE;
//	//		mp = my * TILETESTX + mx;
//	//		if (mp > 0 && mp < TILETESTX*TILETESTY && _tile[mp].attribute == WALL)
//	//		{
//	//			hx = rx; hy = ry; distH = GetDistance(hx, hy, _player.x, _player.y);
//	//			dof = TLENTH;
//	//		}
//	//		else
//	//		{
//	//			rx += xo;
//	//			ry += yo;
//	//			dof += 1;
//	//		}
//	//	}
//
//	//	a[i].x = rx;
//	//	a[i].y = ry;
//	//	int distA = GetDistance(a[i].x, a[i].y, _player.x, _player.y);
//	//	
//	//	dof = 0;
//	//	float distV = TSIZE * TLENTH, vx = _player.x, vy = _player.y;
//	//	float nTan = -tan(ra);
//
//	//	if (ra >= P2 && ra <= P3) { rx = (((int)_player.x / TSIZE)*TSIZE) - 0.0001; ry = _player.y + (_player.x - rx)*nTan; xo = -TSIZE; yo = -xo * nTan; }
//	//	if (ra <= P2 || ra >= P3) { rx = ((int)(_player.x / TSIZE) + 1)		*TSIZE; ry = _player.y + (_player.x - rx)*nTan; xo = TSIZE; yo = -xo * nTan; }
//	//	if (ra == 0 || ra == PI) { rx = _player.x; ry = _player.y; dof = TLENTH; }
//
//	//	while (dof < TLENTH)
//	//	{
//	//		my = (int)(ry) / TSIZE;
//	//		mx = (int)(rx) / TSIZE;
//	//		mp = my * TILETESTX + mx;
//	//		if (mp > 0 && mp < TILETESTX*TILETESTY && _tile[mp].attribute == WALL)
//	//		{
//	//			vx = rx; vy = ry; distV = GetDistance(vx, vy, _player.x, _player.y);
//	//			dof = TLENTH;
//	//		}
//	//		else
//	//		{
//	//			//if (mp > 0 && mp < TILETESTX*TILETESTY)_tile[mp].attribute = VI;
//	//			rx += xo;
//	//			ry += yo;
//	//			dof += 1;
//	//		}
//	//	}
//
//	//	b[i].x = rx;
//	//	b[i].y = ry;
//	//	int distB = GetDistance(b[i].x, b[i].y, _player.x, _player.y);
//	//		
//	//	if (distH < distV) { rx = hx; ry = hy; }
//	//	if (distV < distH) { rx = vx; ry = vy; }
//
//	//	ray[i].x = rx;
//	//	ray[i].y = ry;
//
//	//	ra += 2 * PI / VULSIZE;
//	//	if (ra < 0) { ra += 2 * PI; }
//	//	if (ra > 2 * PI) { ra -= 2 * PI; }
//	//}
//}
//
//void rayCast::render()
//{
//	for (int i = 0; i < TILETESTX*TILETESTY; ++i)
//	{
//		if (_tile[i].attribute == WALL)
//			D2DRENDER->FillRectangle(_tile[i].rc, D2D1COLOR::White, 1.f);
//		else if (_tile[i].attribute == VI)
//			D2DRENDER->DrawRectangle(_tile[i].rc, D2D1COLOR::Blue, 1.f);
//		else
//			D2DRENDER->DrawRectangle(_tile[i].rc, D2D1COLOR::Green, 1.f);
//	}
//
//	for (int i = 0; i < VULSIZE; ++i)
//	{
//		D2DRENDER->DrawLine(s, ray[i], D2D1COLOR::Green, 1.f, 4.f);
//	}
//}
//
//vector<int> rayCast::rayOn(int tileX, int tileY, int x, int y, int arr[])
//{
//	vector<int> index;
//
//	ra = 1 - RD * VULSIZE;
//	if (ra < 0) { ra += (2 * PI); }
//	if (ra > 2 * PI) { ra -= (2 * PI); }
//
//	for (int i = 0; i < VULSIZE; ++i)
//	{
//		dof = 0;
//		float distH = TSIZE * TLENTH, hx = x, hy = y;
//		float aTan = -1 / tan(ra);
//
//		if (ra >= PI) { ry = (((int)y / TSIZE) * TSIZE) - 0.0001;	rx = x + (y - ry)*aTan; yo = -TSIZE; xo = -yo * aTan; }
//		if (ra <= PI) { ry = ((int)(y / TSIZE) + 1)		* TSIZE;	rx = x + (y - ry)*aTan; yo = TSIZE; xo = -yo * aTan; }
//		if (ra == 0 || ra == PI) { rx = x; ry = y; dof = TLENTH; }
//		while (dof < TLENTH)
//		{
//			mx = (int)(rx) / TSIZE;
//			my = (int)(ry) / TSIZE;
//			mp = my * tileX + mx;
//			if (mp > 0 && mp < tileX*tileY && arr[mp] == 4)
//			{
//				hx = rx; hy = ry; distH = GetDistance(x, y, hx, hy);
//
//				dof = TLENTH;
//			}
//			else
//			{
//				index.push_back(mp);
//				rx += xo;
//				ry += yo;
//				dof += 1;
//			}
//		}
//
//		dof = 0;
//		float distV = TSIZE * TLENTH, vx = x, vy = y;
//		float nTan = -tan(ra);
//
//		if (ra >= P2 && ra <= P3) { rx = (((int)x / TSIZE)*TSIZE) - 0.0001; ry = y + (x - rx)*nTan; xo = -TSIZE; yo = -xo * nTan; }
//		if (ra <= P2 || ra >= P3) { rx = ((int)(x / TSIZE) + 1)	    *TSIZE; ry = y + (x - rx)*nTan; xo = TSIZE; yo = -xo * nTan; }
//		if (ra == 0 || ra == PI) { rx = x; ry = y; dof = TLENTH; }
//		while (dof < TLENTH)
//		{
//			my = (int)(ry) / TSIZE;
//			mx = (int)(rx) / TSIZE;
//			mp = my * tileX + mx;
//
//			if (mp > 0 && mp < tileX*tileY && arr[mp] == 4)
//			{
//				vx = rx; vy = ry; distV = GetDistance(x, y, vx, vy);
//				dof = TLENTH;
//			}
//			else
//			{
//				index.push_back(mp);
//				rx += xo;
//				ry += yo;
//				dof += 1;
//			}
//		}
//		if (distH < distV) { rx = hx; ry = hy; }
//		if (distV < distH) { rx = vx; ry = vy; }
//		ray[i].x = rx;
//		ray[i].y = ry;
//		ra += 2 * PI / VULSIZE;
//		if (ra < 0) { ra += (2 * PI); }
//		if (ra > 2 * PI) { ra -= (2 * PI); }
//	}
//	s.x = x;
//	s.y = y;
//	return index;
//}