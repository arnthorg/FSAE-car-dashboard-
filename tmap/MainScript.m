clc
clear all
%%
% Save the serial port name in comPort variable.

comPort = 'COM8';
%% 
% It creates a serial element calling the function "stupSerial"

if(~exist('serialFlag','var'))
    [arduino,serialFlag] = setupSerial(comPort);
end

%%
% Time to create our plot window in order to visualize data collectoed 
% from serial port readings

if (~exist('h','var') || ~ishandle(h))
   h = figure(1);

    set(h,'UserData',1);
end

if (~exist('button','var'))
    button = uicontrol('Style','togglebutton','String','Stop',...
        'Position',[0 0 50 25], 'parent',h);
end


%%
% After creating a system of two axis, a line object through which the data
% will be plotted is also created

if(~exist('myAxes','var'))
    
    buf_len = 50;
    index = 1:buf_len; 
    zeroIndex = zeros(size(index)); 
    tcdata = zeroIndex;
    vcdata = zeroIndex;
    limits = [-20 13];
    
    myAxes = axes('Xlim',[0 buf_len],'Ylim',limits);
    grid on;
    
    l = line(index,[tcdata;zeroIndex]);
    l2 = line(index, [vcdata;zeroIndex]);
    
    drawnow;
end
%%
volts = 0;
temp = 0;
hold on
while (get(button,'Value') == 0 )
    
    tc = readData(arduino,'T');
    tcdata = [tcdata(2:end),tc/10];
    vc = readData(arduino, 'V');
    vcdata = [vcdata(2:end),vc];
    volts(end+1) = vc;
    temp(end+1) =  tc;
    
    set(l,'Ydata',tcdata);
    set(l2,'Ydata',vcdata);
    
    drawnow;
    sprintf('%f , %f',vc, tc)

    pause(1);
end
%%
fclose(instrfind);
filename = strcat('volt-tempdata-', char(datetime(datetime('now','TimeZone','local','Format','d-MMM-y-HH-mm-ss'))), '.mat');
save(filename, 'volts', 'temp');

% To remeber: when you are satisfied with you measurement click on the 
% "stop" button in the bottom left corner of the figure. Now you have to
% close the serial object "Arduino" using the command "fclose(arduino)",
% and close the h figure typing "close(h)". Now in "tcdata" variable you
% have your real time data. 
