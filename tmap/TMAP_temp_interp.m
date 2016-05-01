format short
format compact
 %% 
% k��i sem a� b�r til 256 punkta �r ferli til 
% a� geta sett inn � lookupt�flu

% %% ��arfi, tek SMA � sta�inn.
% % load tempvolt_110-neg2C-TMAP.mat;
% % Taka �t duplicate X gildi svo interp1 ver�i glatt
% for i = 1:(length(tempvolt(:,1)-3)) 
%     if tempvolt(i,1) == tempvolt(i+1,1)
%         tempvolt(i,:) = [];
%     end
% end
%  taka �t gildi ef volts h�kka 
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
