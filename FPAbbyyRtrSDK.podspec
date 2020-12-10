#
# Be sure to run `pod lib lint FPAbbyyRtrSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FPAbbyyRtrSDK'
  s.version          = '0.1.8'
  s.summary          = 'AbbyyRtrSDK pod version'
  s.description      = <<-DESC
This pod was built to provide a pod version of Abbyy Framework which is licensed.
ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.
                       DESC

  s.homepage         = 'https://github.com/lmahia/FPAbbyyRtrSDK'
  s.license          = { :type => 'Commercial', :file => 'LICENSE' }
  s.author           = { 'Leandro Mahia' => 'lmahia@facephi.com' }
  s.source           = { :git => 'https://github.com/lmahia/FPAbbyyRtrSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true

  s.xcconfig = {
    'ENABLE_BITCODE'                       => 'NO',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 i386'
  }

  s.source_files   = 'FPAbbyyRtrSDK/Classes/**/*'

  s.preserve_paths = 'FPAbbyyRtrSDK/Frameworks/**/*'

  s.ios.vendored_frameworks = [
    'FPAbbyyRtrSDK/Frameworks/AbbyyRtrSDK.framework',
    'FPAbbyyRtrSDK/Frameworks/AbbyyZLib.framework',
    'FPAbbyyRtrSDK/Frameworks/ExtraNeoML.Dnn.framework',
    'FPAbbyyRtrSDK/Frameworks/FineMachineLearning.framework',
    'FPAbbyyRtrSDK/Frameworks/FineMachineLearningExt.framework',
    'FPAbbyyRtrSDK/Frameworks/FineObj.framework',
    'FPAbbyyRtrSDK/Frameworks/Mobile.imaging.framework',
    'FPAbbyyRtrSDK/Frameworks/Mobile.Ocr4.framework',
    'FPAbbyyRtrSDK/Frameworks/Mobile.SDK.framework',
    'FPAbbyyRtrSDK/Frameworks/Mobile.Vision.framework',
    'FPAbbyyRtrSDK/Frameworks/NeoMathEngine.framework',
    'FPAbbyyRtrSDK/Frameworks/NeoML.framework',
    'FPAbbyyRtrSDK/Frameworks/PortLayer.framework'
  ]

  s.libraries = 'c++', 'z'

end
