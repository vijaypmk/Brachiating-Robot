qz=0;
qr=1;
L = Link('d', 0, 'a', 1, 'alpha', 0);
L2 = Link('d', 0, 'a', 0.2,'alpha', 0);
L3 = Link('d', 0, 'a', 0, 'alpha', 0);
bot=SerialLink([L3 L L L3], 'name', 'HMREL');

plotopt = {'noraise', 'nobase', 'noshadow', 'nowrist', 'nojaxes', 'delay', 0};
bot.plot([0 0 0 0], plotopt{:});
hold on
t = [0:.05:10]';
t1= [0:.05:10]';
q  = jtraj(-1, 1, t);
qb=jtraj(1,-1,t1);
q1 = jtraj(0,.25,t);
qb1= jtraj(0.25,0,t1);
q2 = jtraj(-1,1,t);
qb2= jtraj(1,-1,t1);
q3 = jtraj(7,7,t);
qb3= jtraj(7,7,t1);
%Q=bot.fkine(q);
%Q1=bot.fkine(q1);
clf; axis([-3 1 -2 2 -1.5 0.5]); %set(gca,'Zdir', 'reverse')
%hold on
bot.plot([q q1 q2 q3],plotopt{:});
hold on
bot.plot([qb qb1 qb2 qb3],plotopt{:});
hold on;
for k=1:10;
for i=1:200
bot.animate(gait([q q1 q2 q3],i, 0, 0));
hold on
drawnow;
end


for i=1:200
bot.animate(gait([qb qb1 qb2 qb3],i, 0, 0));
hold on
drawnow;
end
end