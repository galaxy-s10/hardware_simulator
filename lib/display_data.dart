enum MultiDisplayMode {
  extend,        
  primaryOnly,   
  secondaryOnly,
  duplicate,     
  unknown
}

class DisplayData {
  final int index;
  final int width;
  final int height;
  final int refreshRate;
  final bool isVirtual;
  final String displayName;
  final String deviceName;
  final bool active;
  final int displayUid;
  final int orientation;
  
  DisplayData({
    required this.index,
    required this.width,
    required this.height,
    required this.refreshRate,
    required this.isVirtual,
    required this.displayName,
    required this.deviceName,
    required this.active,
    required this.displayUid,
    required this.orientation,
  });
  
  factory DisplayData.fromMap(Map<String, dynamic> map) {
    return DisplayData(
      index: map['index'] ?? 0,
      width: map['width'] ?? 1920,
      height: map['height'] ?? 1080,
      refreshRate: map['refreshRate'] ?? 60,  
      isVirtual: map['isVirtual'] ?? false,  
      displayName: map['displayName'] ?? '',  
      deviceName: map['deviceName'] ?? '',   
      active: map['active'] ?? true,
      displayUid: map['displayUid'] ?? 0,
      orientation: map['orientation'] ?? 0,
    );
  }
}
