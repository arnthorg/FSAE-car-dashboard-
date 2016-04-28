format short
format compact
 %%

%%
load hitanemar.mat
vq = interp1(HitanemarV,HitanemarC, 0:5/256:5-5/256);
hold on
plot(0:5/256:5-5/256, vq, 'x')
plot(HitanemarV, HitanemarC, 'o')
newq = round(vq)+30;
%%
strengur = '';
for i = 1:length(newq)
    if isnan(newq(i))
        strengur = strcat(strengur, ', ', '0');
    else
        strengur = strcat(strengur, ', ', num2str(newq(i)));
    end
end
  