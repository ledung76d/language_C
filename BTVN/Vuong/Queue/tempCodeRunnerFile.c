makeNullQueue(&q);
    enQueue(&q, 5);
    enQueue(&q, 6);
    int a;
    deQueue(&q, &a);
    printf("%d\n", a);
    deQueue(&q, &a);
    printf("%d\n", a);
    deQueue(&q, &a);