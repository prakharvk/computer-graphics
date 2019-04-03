    #include <graphics.h>
         
    main()
    {
       int gd = DETECT, gm;
     
       initgraph(&gd, &gm, 0);
     
       setcolor(RED);
       circle(100,100,50);
       floodfill(100,100,RED);
       
       getch();
       closegraph();
       return 0;
    }
