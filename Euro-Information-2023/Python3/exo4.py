from math import pi
from random import choice

def circle_from_three_points_or_less(P):
    if len(P)==0:
        return (0,0),0
    elif len(P)==1:
        p,=P
        return p,0
    elif len(P)==2:
        return circle_from_two_points(*[coord for point in P for coord in point])
    elif len(P)==3:
        return circle_from_three_points(*[coord for point in P for coord in point])

def circle_from_two_points(x1,y1,x2,y2):
    return ((x1+x2)/2,(y1+y2)/2) , ((x1-x2)**2+(y1-y2)**2)/4

def circle_from_three_points(x1, y1, x2, y2, x3, y3) :
    x12, x13 = x1 - x2, x1 - x3
    y12, y13 = y1 - y2, y1 - y3
    y31, y21 = y3 - y1, y2 - y1
    x31, x21 = x3 - x1, x2 - x1
 
    sx13 = x1*x1 - x3*x3
    sy13 = y1*y1 - y3*y3
    sx21 = x2*x2 - x1*x1
    sy21 = y2*y2 - y1*y1
         
    X = -(sx13*y12+sy13*y12+sx21*y13+sy21*y13) / (2*(x31*y12-x21*y13))
    Y = -(sx13*x12+sy13*x12+sx21*x13+sy21*x13) / (2*(y31*x12-y21*x13))
 
    c = - x1*x1 - y1*y1 + 2*X*x1 + 2*Y*y1
 
    r_squared = X*X+Y*Y-c

    return (X,Y),r_squared

def welzl(P,R):

    if not P or len(R)==3:
        return circle_from_three_points_or_less(R)

    p = choice(list(P))

    c,r_squared = welzl(P-{p},R)
    if (p[0]-c[0])**2 + (p[1]-c[1])**2 <= r_squared:
        return c,r_squared

    return welzl(P - {p},R | {p})

P = {tuple(map(int,input().split())) for _ in range(int(input()))}

c,r_squared = welzl(P,set())

print(f"{pi*r_squared:.5f}")
