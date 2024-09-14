  int x, y, z;
            x = child.u;
            y = child.v;
            z = child.c;

            if (dis[x] < INT_MAX && dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
            }