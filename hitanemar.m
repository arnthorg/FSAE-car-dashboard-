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
        strengur = strcat(strengur, ',   0');
    else
%         strengur = strcat(strengur, ',', num2str(newq(i)));
        if newq(i) > 99
            strengur = strcat(strengur, sprintf(', %d', newq(i)));
        elseif (newq(i) >9) | (newq(i) <0)
            strengur = strcat(strengur, sprintf(',  %d', newq(i)));
        else
            strengur = strcat(strengur, sprintf(',   %d', newq(i)));
        end
    if mod(i, 16) == 0
      strengur = strcat(strengur, '\n');
    end
    end
end
disp(strengur)
  