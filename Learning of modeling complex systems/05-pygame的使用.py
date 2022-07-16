# -*- coding = utf-8 -*-
# @Time: 2022/7/15 11:30
# @Author: 陌言
# @File: 05-pygame的使用.py
# @SoftWare: PyCharm
import pygame, sys
from pygame.locals import *
pygame.init()
DISPLAYSURE = pygame.display.set_mode((500, 400))
pygame.display.set_caption('Drawing')
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
DISPLAYSURE.fill(WHITE)
pygame.draw.polygon(DISPLAYSURE, GREEN, ((146, 0), (291, 106), (236, 277), (56, 277), (0, 106)))
pygame.draw.line(DISPLAYSURE, BLUE, (60, 60), (120, 60), 4)
pygame.draw.line(DISPLAYSURE, BLUE, (120, 60), (60, 120))
pygame.draw.line(DISPLAYSURE, BLUE, (60, 120), (120, 120), 4)
pygame.draw.circle(DISPLAYSURE, BLUE, (300, 50), 20, 0)
pygame.draw.ellipse(DISPLAYSURE, RED, (300, 250, 40, 80), 1)
pygame.draw.rect(DISPLAYSURE, RED, (200, 150, 100, 50))
pixObj = pygame.PixelArray(DISPLAYSURE)
pixObj[480][380] = BLACK
pixObj[482][382] = BLACK
pixObj[484][384] = BLACK
pixObj[486][386] = BLACK
pixObj[488][388] = BLACK
pygame.display.flip()
pygame.display.update()
clock = pygame.time.Clock()
clock.tick(15)
del pixObj
while True:
    for event in pygame.event.get():
        print(event)
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
            pygame.display.update()