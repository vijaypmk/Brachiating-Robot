l = Link([0, 0, 0, 0, 0]);
l(2) = Link([1, 1, 1, 1, 1]);
%l(3) = Link([1, 1, 1, 1, 1]);
R = SerialLink(l);
R.plotopt = {'workspace' [-2,2,-2,2,-2,7]};
%R.plotopt= [1,1,1,1,1,1];
R.plot([0,1])
%R.teach()
