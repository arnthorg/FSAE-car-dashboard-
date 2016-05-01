format short
format compact
 %% 
% kóði sem að býr til 256 punkta úr ferli til 
% að geta sett inn í lookuptöflu

% %% óþarfi, tek SMA í staðinn.
% % load tempvolt_110-neg2C-TMAP.mat;
% % Taka út duplicate X gildi svo interp1 verði glatt
% for i = 1:(length(tempvolt(:,1)-3)) 
%     if tempvolt(i,1) == tempvolt(i+1,1)
%         tempvolt(i,:) = [];
%     end
% end
%  taka út gildi ef volts hækka 
% for i = 1:(length(tempvolt(:,1)-3)) 
%     if tempvolt(i,1) > tempvolt(i+1,1)
%         tempvolt(i,:) = [];
%     end
% end

%% sma 
weight = 4;
output = tsmovavg(tempvolt,'e',weight,1);
for i = 1:(weight-1)
    output(1,:) = [];
end
hold on
plot(output(:,1), output(:,2))
plot(tempvolt(:,1), tempvolt(:,2))
%%
vq = interp1(output(:,1),output(:,2), 0:5/256:5-5/256);
hold on
plot(0:5/256:5-5/256, vq, 'x')
plot(output(:,1),output(:,2), 'o')
newq = round(vq);
%%
strengur = '';
for i = 1:length(newq)
    if isnan(newq(i))
        strengur = strcat(strengur, ', ', '0');
    else
        strengur = strcat(strengur, ', ', num2str(newq(i)));
    end
end
disp(strengur)
