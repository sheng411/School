def points():
    for i in range(1,13):
        x = 200 + 130*math.sin(2*math.pi*i/12)
        y = 200 - 130*math.cos(2*math.pi*i/12)
        canvas.create_text(x,y,text=i)