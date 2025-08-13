#
# Be sure to run `pod lib lint MKGatewayMiniTwo.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MKGatewayMiniTwo'
  s.version          = '0.0.1'
  s.summary          = 'A short description of MKGatewayMiniTwo.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/lovexiaoxia/MKGatewayMiniTwo'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'lovexiaoxia' => 'aadyx2007@163.com' }
  s.source           = { :git => 'https://github.com/lovexiaoxia/MKGatewayMiniTwo.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '14.0'
  
  s.resource_bundles = {
    'MKGatewayMiniTwo' => ['MKGatewayMiniTwo/Assets/*.png']
  }

  s.subspec 'Target' do |ss|
    
    ss.source_files = 'MKGatewayMiniTwo/Classes/Target/**'
    
    ss.dependency 'MKBaseModuleLibrary'
    ss.dependency 'MKGatewayMiniTwo/Functions'
  
  end
  
  s.subspec 'CTMediator' do |ss|
    
    ss.source_files = 'MKGatewayMiniTwo/Classes/CTMediator/**'
    
    ss.dependency 'CTMediator'
    ss.dependency 'MKBaseModuleLibrary'
  
  end
  
  s.subspec 'DeviceModel' do |ss|
    
    ss.source_files = 'MKGatewayMiniTwo/Classes/DeviceModel/**'

    ss.dependency 'MKBaseModuleLibrary'
    ss.dependency 'MKGatewayMiniTwo/SDK/MQTT'
  
  end
  
  s.subspec 'Expand' do |ss|
    
    ss.subspec 'BleBaseController' do |sss|
      
      sss.source_files = 'MKGatewayMiniTwo/Classes/Expand/BleBaseController/**'
    
    
      sss.dependency 'MKGatewayMiniTwo/SDK/BLE'
    end
  
    ss.subspec 'BaseController' do |sss|
      
      sss.source_files = 'MKGatewayMiniTwo/Classes/Expand/BaseController/**'
    
    
      sss.dependency 'MKGatewayMiniTwo/SDK/MQTT'
      sss.dependency 'MKGatewayMiniTwo/DeviceModel'
    end
    
    ss.subspec 'DatabaseManager' do |sss|
      
      sss.source_files = 'MKGatewayMiniTwo/Classes/Expand/DatabaseManager/**'
    
    
      sss.dependency 'FMDB'
      sss.dependency 'MKGatewayMiniTwo/DeviceModel'
    end
    
    ss.subspec 'ExcelManager' do |sss|
      
      sss.source_files = 'MKGatewayMiniTwo/Classes/Expand/ExcelManager/**'
    
    
      sss.dependency 'libxlsxwriter'
      sss.dependency 'SSZipArchive'
    end
    
    ss.subspec 'View' do |sss|
      
      sss.subspec 'AdvNormalCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/AdvNormalCell/**'
      end
      
      sss.subspec 'AdvTriggerCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/AdvTriggerCell/**'
      end
      
      sss.subspec 'AdvTriggerTwoStateCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/AdvTriggerTwoStateCell/**'
      end
      
      sss.subspec 'AlertView' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/AlertView/**'
      end
      
      sss.subspec 'BleWifiSettingsCertCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/BleWifiSettingsCertCell/**'
      end
      
      sss.subspec 'ButtonFirmwareCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/ButtonFirmwareCell/**'
      end
      
      sss.subspec 'BXPAdvParamsCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/BXPAdvParamsCell/**'
      end
      
      sss.subspec 'BXPButtonAccHeaderView' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/BXPButtonAccHeaderView/**'
      end
      
      sss.subspec 'MKCSFilterCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/MKCSFilterCell/**'
      end
      
      sss.subspec 'PressEventCountCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/PressEventCountCell/**'
      end
      
      sss.subspec 'RemoteReminderCell' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/RemoteReminderCell/**'
      end
      
      sss.subspec 'UserCredentialsView' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/View/UserCredentialsView/**'
      end
        
    end
    
    ss.subspec 'ImportServerPage' do |sss|
      sss.subspec 'Controller' do |ssss|
        ssss.source_files = 'MKGatewayMiniTwo/Classes/Expand/ImportServerPage/Controller/**'
      end
    end
    
    ss.dependency 'MKBaseModuleLibrary'
    ss.dependency 'MKCustomUIModule'
  
  end
  
  s.subspec 'SDK' do |ss|
      
    ss.subspec 'BLE' do |sss|
      sss.source_files = 'MKGatewayMiniTwo/Classes/SDK/BLE/**'
      
      sss.dependency 'MKBaseBleModule'
    end
    
    ss.subspec 'MQTT' do |sss|
        sss.subspec 'Manager' do |ssss|
            ssss.source_files = 'MKGatewayMiniTwo/Classes/SDK/MQTT/Manager/**'
            
            ssss.dependency 'MKBaseModuleLibrary'
            ssss.dependency 'MKBaseMQTTModule'
        end
        
        sss.subspec 'SDK' do |ssss|
            ssss.source_files = 'MKGatewayMiniTwo/Classes/SDK/MQTT/SDK/**'
            
            ssss.dependency 'MKBaseModuleLibrary'
            ssss.dependency 'MKGatewayMiniTwo/SDK/MQTT/Manager'
        end
    end
    
  end
  
  s.subspec 'Functions' do |ss|
    
    ss.subspec 'AddDeviceModules' do |sss|
        sss.subspec 'ParamsModel'  do |ssss|
            ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/ParamsModel/**'
        end
        sss.subspec 'Pages' do |ssss|
            ssss.subspec 'BleDeviceInfoPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleDeviceInfoPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleDeviceInfoPage/Model'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleDeviceInfoPage/Model/**'
                end
            end
            
            ssss.subspec 'BleDeviceInfoV2Page' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleDeviceInfoV2Page/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleDeviceInfoV2Page/Model'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleDeviceInfoV2Page/Model/**'
                end
            end
            
            ssss.subspec 'BleScannerFilterPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleScannerFilterPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleScannerFilterPage/Model'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleScannerFilterPage/Model/**'
                end
            end
            
            ssss.subspec 'BleWifiSettingsPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleWifiSettingsPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleWifiSettingsPage/Model'
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleWifiSettingsPage/View'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/NearbyWifiPage'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleWifiSettingsPage/Model/**'
                end
                
                sssss.subspec 'View' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleWifiSettingsPage/View/**'
                end
            end
            
            ssss.subspec 'BleAdvBeaconPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleAdvBeaconPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleAdvBeaconPage/Model'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleAdvBeaconPage/Model/**'
                end
            end
            
            ssss.subspec 'BleAdvBeaconV2Page' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleAdvBeaconV2Page/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleAdvBeaconV2Page/Model'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/BleAdvBeaconV2Page/Model/**'
                end
            end
            
            ssss.subspec 'ConnectSuccessPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/ConnectSuccessPage/Controller/**'
                end
            end
            
            ssss.subspec 'DeviceParamsListPage' do |sssss|
              sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/DeviceParamsListPage/Controller/**'
              
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleDeviceInfoPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleScannerFilterPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleWifiSettingsPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleAdvBeaconPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ConnectSuccessPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/NTPTimezonePage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ServerForDevice'
              end
            end
            
            ssss.subspec 'DeviceParamsListV2Page' do |sssss|
              sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/DeviceParamsListV2Page/Controller/**'
              
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleAdvBeaconV2Page'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleDeviceInfoV2Page'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleWifiSettingsPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/BleScannerFilterPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ConnectSuccessPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/NTPTimezonePage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ServerForDevice'
              end
            end
            
            ssss.subspec 'NearbyWifiPage' do |sssss|
              sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/NearbyWifiPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/NearbyWifiPage/View'
              end
              
              sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/NearbyWifiPage/View/**'
              end
            end
            
            ssss.subspec 'NTPTimezonePage' do |sssss|
              sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/NTPTimezonePage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/NTPTimezonePage/Model'
              end
              
              sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/NTPTimezonePage/Model/**'
              end
            end
            
            ssss.subspec 'ServerForDevice' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/ServerForDevice/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ServerForDevice/Model'
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/Pages/ServerForDevice/View'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/ServerForDevice/Model/**'
                end
                
                sssss.subspec 'View' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/AddDeviceModules/Pages/ServerForDevice/View/**'
                end
            end
            
            ssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules/ParamsModel'
            
        end
        
    end
    
    ss.subspec 'DeviceDataPage' do |sss|
        sss.subspec 'Controller' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/DeviceDataPage/Controller/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/DeviceDataPage/View'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages'
          ssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadOptionPage'
          ssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadOptionV2Page'
          ssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules'
        end
        
        sss.subspec 'View' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/DeviceDataPage/View/**'
        end
    end
    
    ss.subspec 'DeviceListPage' do |sss|
        sss.subspec 'Controller' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/DeviceListPage/Controller/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/DeviceListPage/View'
          ssss.dependency 'MKGatewayMiniTwo/Functions/DeviceListPage/Model'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/ServerForApp'
          ssss.dependency 'MKGatewayMiniTwo/Functions/ScanPage'
          ssss.dependency 'MKGatewayMiniTwo/Functions/DeviceDataPage'
        end
        
        sss.subspec 'Model' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/DeviceListPage/Model/**'
        end
        
        sss.subspec 'View' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/DeviceListPage/View/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/DeviceListPage/Model'
        end
    end
    
    ss.subspec 'FilterPages' do |sss|
      
      sss.subspec 'DataUploadIntervalPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/DataUploadIntervalPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/DataUploadIntervalPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/DataUploadIntervalPage/Model/**'
        end
      end
      
      sss.subspec 'DuplicateDataFilterPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/DuplicateDataFilterPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/DuplicateDataFilterPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/DuplicateDataFilterPage/Model/**'
        end
      end
          
      sss.subspec 'FilterByAdvNamePage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByAdvNamePage/Controller/**'
            
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByAdvNamePage/Model'
              
        end
          
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByAdvNamePage/Model/**'
        end
      end
      
      sss.subspec 'FilterByBeaconPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByBeaconPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByBeaconPage/Header'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByBeaconPage/Model'
          
        end
        
        ssss.subspec 'Header' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByBeaconPage/Header/**'
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByBeaconPage/Model/**'
          
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByBeaconPage/Header'
        end
      end
      
      sss.subspec 'FilterByButtonPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByButtonPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByButtonPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByButtonPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByMacPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByMacPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByMacPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByMacPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByOtherPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByOtherPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByOtherPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByOtherPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByPirPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByPirPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByPirPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByPirPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByRawDataPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByRawDataPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByRawDataPage/Model'
          
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByBeaconPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByUIDPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByURLPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTLMPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTofPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByButtonPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTag'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByPirPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByOtherPage'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByRawDataPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByRawDataV2Page' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByRawDataV2Page/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByRawDataV2Page/Model'
          
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByBeaconPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByUIDPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByURLPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTLMPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByButtonPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTag'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByPirPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTofPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByOtherPage'
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByRawDataV2Page/Model/**'
        end
      end
      
      sss.subspec 'FilterByTag' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTag/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTag/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTag/Model/**'
        end
      end
      
      sss.subspec 'FilterByTLMPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTLMPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTLMPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTLMPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByTofPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTofPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByTofPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByTofPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByUIDPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByUIDPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByUIDPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByUIDPage/Model/**'
        end
      end
      
      sss.subspec 'FilterByURLPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByURLPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByURLPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/FilterByURLPage/Model/**'
        end
      end
      
      sss.subspec 'UploadDataOptionPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadDataOptionPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadDataOptionPage/Model'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadDataOptionPage/Model/**'
        end
      end
      
      sss.subspec 'UploadOptionPage' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadOptionPage/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadOptionPage/Model'
          
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/DuplicateDataFilterPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadDataOptionPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByMacPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByAdvNamePage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByRawDataPage'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadOptionPage/Model/**'
        end
        
      end
      
      sss.subspec 'UploadOptionV2Page' do |ssss|
        ssss.subspec 'Controller' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadOptionV2Page/Controller/**'
        
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadOptionV2Page/Model'
          
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/DuplicateDataFilterPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/DataUploadIntervalPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/UploadDataOptionPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByMacPage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByAdvNamePage'
          sssss.dependency 'MKGatewayMiniTwo/Functions/FilterPages/FilterByRawDataV2Page'
          
        end
      
        ssss.subspec 'Model' do |sssss|
          sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/FilterPages/UploadOptionV2Page/Model/**'
        end
        
      end
      
    end
    
    ss.subspec 'ManageBleModules' do |sss|
      
      sss.subspec 'ButtonDFUPage' do |ssss|
          ssss.subspec 'Controller' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/ButtonDFUPage/Controller/**'
              
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage/Model'
          end
          
          ssss.subspec 'Model' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/ButtonDFUPage/Model/**'
          end
      end
      
      sss.subspec 'BXPBCRPages' do |ssss|
        ssss.subspec 'BXPButtonCRPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRPage/Controller/**'
                                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRRemoteReminderPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAccDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAdvParamsPage'
            end
        end
        ssss.subspec 'BXPButtonCRRemoteReminderPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRRemoteReminderPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRRemoteReminderPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRRemoteReminderPage/Model/**'
            end
        end
        ssss.subspec 'BXPButtonCRAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAccDataPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAccDataPage/View'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAccDataPage/View/**'
            end
        end
        ssss.subspec 'BXPButtonCRAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRAdvParamsPage/Model/**'
            end
        end
        ssss.subspec 'BXPButtonCREventAlarmPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage/View'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage/Model'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage/View/**'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBCRPages/BXPButtonCREventAlarmPage/Model/**'
            end
        end
      end
      
      sss.subspec 'BXPBDPages' do |ssss|
        ssss.subspec 'BXPButtonPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonPage/View'
                                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonRemoteReminderPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonAccDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonAdvParamsPage'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonPage/View/**'
            end
        end
        ssss.subspec 'BXPButtonRemoteReminderPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonRemoteReminderPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonRemoteReminderPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonRemoteReminderPage/Model/**'
            end
        end
        ssss.subspec 'BXPButtonAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonAccDataPage/Controller/**'
                
            end
        end
        ssss.subspec 'BXPButtonAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPBDPages/BXPButtonAdvParamsPage/Model/**'
            end
        end
      end
      
      sss.subspec 'BXPCPages' do |ssss|
        ssss.subspec 'BXPCAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCAccDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPCAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCAdvParamsPage/Model/**'
            end
        end
        ssss.subspec 'BXPCPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCPage/Controller/**'
                                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCRealTimeTHDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCHistoricalTHDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCAccDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCTHDataSampleRatePage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCAdvParamsPage'
                
            end
        end
        ssss.subspec 'BXPCHistoricalTHDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCHistoricalTHDataPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCHistoricalTHDataPage/View'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCHistoricalTHDataPage/View/**'
            end
        end
        ssss.subspec 'BXPCRealTimeTHDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCRealTimeTHDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPCTHDataSampleRatePage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCTHDataSampleRatePage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCTHDataSampleRatePage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPCPages/BXPCTHDataSampleRatePage/Model/**'
            end
        end
      end
      
      sss.subspec 'BXPDPages' do |ssss|
        ssss.subspec 'BXPDPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDPage/Controller/**'
          
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDAccDataPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDAccParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDAdvParamsPage'
          end
        end
        ssss.subspec 'BXPDAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDAccDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPDAccParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDAccParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDAccParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDAccParamsPage/Model/**'
            end
        end
        ssss.subspec 'BXPDAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPDPages/BXPDAdvParamsPage/Model/**'
            end
        end
      end
      
      sss.subspec 'BXPSPages' do |ssss|
        ssss.subspec 'BXPSAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSAccDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPSAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage/Controller/**'

                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage/Model'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage/View'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage/Model/**'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage/View/**'
            end
        end
        ssss.subspec 'BXPSHallCountPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSHallCountPage/Controller/**'
            end
        end
        ssss.subspec 'BXPSPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSPage/Controller/**'
                                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSRealTimeTHDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSHistoricalTHDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSAccDataPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSTHDataSampleRatePage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSHallCountPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSRemoteReminderPage'
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSAdvParamsPage'
            end
        end
        ssss.subspec 'BXPSHistoricalTHDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSHistoricalTHDataPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSHistoricalTHDataPage/View'
            end
            sssss.subspec 'View' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSHistoricalTHDataPage/View/**'
            end
        end
        ssss.subspec 'BXPSRealTimeTHDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSRealTimeTHDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPSTHDataSampleRatePage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSTHDataSampleRatePage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSTHDataSampleRatePage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSTHDataSampleRatePage/Model/**'
            end
        end
        ssss.subspec 'BXPSRemoteReminderPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSRemoteReminderPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSRemoteReminderPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPSPages/BXPSRemoteReminderPage/Model/**'
            end
        end
      end
      
      sss.subspec 'BXPTPages' do |ssss|
        ssss.subspec 'BXPTAccDataPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTAccDataPage/Controller/**'
            end
        end
        ssss.subspec 'BXPTAccParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTAccParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTAccParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTAccParamsPage/Model/**'
            end
        end
        ssss.subspec 'BXPTAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTAdvParamsPage/Model/**'
            end
        end
        ssss.subspec 'BXPTMotionEventPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTMotionEventPage/Controller/**'
                
            end
        end
        ssss.subspec 'BXPTPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTPage/Controller/**'
          
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTAccDataPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTAccParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTAdvParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTMotionEventPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTRemoteReminderPage'
          end
        end
        ssss.subspec 'BXPTRemoteReminderPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTRemoteReminderPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTRemoteReminderPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/BXPTPages/BXPTRemoteReminderPage/Model/**'
            end
        end
      end
      
      sss.subspec 'ManageBleDevicesPage' do |ssss|
          ssss.subspec 'Controller' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/ManageBleDevicesPage/Controller/**'
              
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ManageBleDevicesPage/View'
              
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBDPages/BXPButtonPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPBCRPages/BXPButtonCRPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPCPages/BXPCPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPDPages/BXPDPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPTPages/BXPTPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/BXPSPages/BXPSPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages'
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/NormalConnectedPage'
          end
          
          ssss.subspec 'View' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/ManageBleDevicesPage/View/**'
          end
      end
      
      sss.subspec 'MKTofPages' do |ssss|
        ssss.subspec 'TofAccDataPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofAccDataPage/Controller/**'
          
          end
        end
        ssss.subspec 'TofAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofAdvParamsPage/Model/**'
            end
        end
        ssss.subspec 'TofPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofPage/Controller/**'
          
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofAdvParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofSensorDataPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofSensorParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofAccDataPage'
            
          end
        end
        ssss.subspec 'TofSensorDataPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofSensorDataPage/Controller/**'
          
          end
        end
        ssss.subspec 'TofSensorParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofSensorParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/MKTofPages/TofSensorParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/MKTofPages/TofSensorParamsPage/Model/**'
            end
        end
      end
      
      sss.subspec 'NormalConnectedPage' do |ssss|
          ssss.subspec 'Controller' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/NormalConnectedPage/Controller/**'
              
              sssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/NormalConnectedPage/View'
          end
          
          ssss.subspec 'View' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/NormalConnectedPage/View/**'
          end
      end
      
      sss.subspec 'PirPages' do |ssss|
        ssss.subspec 'PirAdvParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirAdvParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages/PirAdvParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirAdvParamsPage/Model/**'
            end
        end
        ssss.subspec 'PirPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirPage/Controller/**'
          
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/ButtonDFUPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages/PirAdvParamsPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages/PirSensorDataPage'
            ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages/PirSensorParamsPage'
          end
        end
        ssss.subspec 'PirSensorDataPage' do |sssss|
          sssss.subspec 'Controller' do |ssssss|
            ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirSensorDataPage/Controller/**'
          
          end
        end
        ssss.subspec 'PirSensorParamsPage' do |sssss|
            sssss.subspec 'Controller' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirSensorParamsPage/Controller/**'
                
                ssssss.dependency 'MKGatewayMiniTwo/Functions/ManageBleModules/PirPages/PirSensorParamsPage/Model'
            end
            sssss.subspec 'Model' do |ssssss|
                ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ManageBleModules/PirPages/PirSensorParamsPage/Model/**'
            end
        end
      end
    end
    
    ss.subspec 'ScanPage' do |sss|
        sss.subspec 'Controller' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ScanPage/Controller/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/ScanPage/Model'
          ssss.dependency 'MKGatewayMiniTwo/Functions/ScanPage/View'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/AddDeviceModules'
        end
        
        sss.subspec 'Model' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ScanPage/Model/**'
        end
        
        sss.subspec 'View' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ScanPage/View/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/ScanPage/Model'
        end
    end
    
    ss.subspec 'ServerForApp' do |sss|
        sss.subspec 'Controller' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ServerForApp/Controller/**'
          
          ssss.dependency 'MKGatewayMiniTwo/Functions/ServerForApp/Model'
          ssss.dependency 'MKGatewayMiniTwo/Functions/ServerForApp/View'
        end
        
        sss.subspec 'Model' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ServerForApp/Model/**'
        end
        
        sss.subspec 'View' do |ssss|
          ssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/ServerForApp/View/**'
        end
    end
    
    ss.subspec 'SettingPages' do |sss|
        sss.subspec 'DeviceInfoPage' do |ssss|
            ssss.subspec 'Controller' do |sssss|
                sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/DeviceInfoPage/Controller/**'
                sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/DeviceInfoPage/Model'
            end
            ssss.subspec 'Model' do |sssss|
                sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/DeviceInfoPage/Model/**'
            end
        end
        
        sss.subspec 'ModifyNetworkPages' do |ssss|
            
            ssss.subspec 'MqttParamsListPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttParamsListPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttParamsListPage/Model'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttServerPage'
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttWifiSettingsPage'
                end
                
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttParamsListPage/Model/**'
                end
            end
            
            ssss.subspec 'MqttServerPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttServerPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttServerPage/Model'
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttServerPage/View'
                end
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttServerPage/Model/**'
                end
                sssss.subspec 'View' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttServerPage/View/**'
                end
            end
            
            ssss.subspec 'MqttWifiSettingsPage' do |sssss|
                sssss.subspec 'Controller' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttWifiSettingsPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages/MqttWifiSettingsPage/Model'
                end
                sssss.subspec 'Model' do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/ModifyNetworkPages/MqttWifiSettingsPage/Model/**'
                end
            end
            
        end
        
        sss.subspec 'NormalSettings' do |ssss|
          
            ssss.subspec 'AdvBeaconPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/AdvBeaconPage/Controller/**'
                
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/AdvBeaconPage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/AdvBeaconPage/Model/**'
                end
            end
            
            ssss.subspec 'AdvBeaconV2Page' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/AdvBeaconV2Page/Controller/**'
                
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/AdvBeaconV2Page/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/AdvBeaconV2Page/Model/**'
                end
            end
          
            ssss.subspec 'CommunicatePage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/CommunicatePage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/CommunicatePage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/CommunicatePage/Model/**'
                end
            end
            
            ssss.subspec 'DataReportPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/DataReportPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/DataReportPage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/DataReportPage/Model/**'
                end
            end
            
            ssss.subspec 'IndicatorSettingsPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/IndicatorSettingsPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/IndicatorSettingsPage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/IndicatorSettingsPage/Model/**'
                end
            end
            
            ssss.subspec 'NetworkStatusPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/NetworkStatusPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/NetworkStatusPage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/NetworkStatusPage/Model/**'
                end
            end
            
            ssss.subspec 'NTPServerPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/NTPServerPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/NTPServerPage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/NTPServerPage/Model/**'
                end
            end
            
            ssss.subspec 'ReconnectTimePage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/ReconnectTimePage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/ReconnectTimePage/Model'
                end
                sssss.subspec 'Model'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/ReconnectTimePage/Model/**'
                end
            end
            
            ssss.subspec 'ResetByButtonPage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/ResetByButtonPage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/ResetByButtonPage/View'
                end
                sssss.subspec 'View'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/ResetByButtonPage/View/**'
                end
            end
            
            ssss.subspec 'SystemTimePage' do |sssss|
                sssss.subspec 'Controller'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/SystemTimePage/Controller/**'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/SystemTimePage/View'
                  
                  ssssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings/NTPServerPage'
                end
                sssss.subspec 'View'  do |ssssss|
                  ssssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/NormalSettings/SystemTimePage/View/**'
                end
            end
            
        end
        
        sss.subspec 'OTAPage' do |ssss|
            ssss.subspec 'Controller' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/OTAPage/Controller/**'
              
              sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/OTAPage/Model'
            end
            ssss.subspec 'Model' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/OTAPage/Model/**'
            end
        end
        
        sss.subspec 'SettingPage' do |ssss|
            ssss.subspec 'Controller' do |sssss|
              sssss.source_files = 'MKGatewayMiniTwo/Classes/Functions/SettingPages/SettingPage/Controller/**'
                            
              sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/DeviceInfoPage'
              sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/ModifyNetworkPages'
              sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/NormalSettings'
              sssss.dependency 'MKGatewayMiniTwo/Functions/SettingPages/OTAPage'
            end
        end
        
    end
    
    ss.dependency 'MKGatewayMiniTwo/SDK'
    ss.dependency 'MKGatewayMiniTwo/Expand'
    ss.dependency 'MKGatewayMiniTwo/CTMediator'
    ss.dependency 'MKGatewayMiniTwo/DeviceModel'
    ss.dependency 'MKGatewayMiniTwo/CTMediator'
  
    ss.dependency 'MKBaseModuleLibrary'
    ss.dependency 'MKCustomUIModule'
    
    ss.dependency 'MLInputDodger'
    
  end
  
end
