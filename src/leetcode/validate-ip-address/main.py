class Solution:
    def validIPAddress(self, IP: str) -> str:
        NEITHER = 'Neither'
        filter = '-'
        
        def ipv4(ip: str):
            nums = ip.split('.')
            if len(nums) != 4:
                return NEITHER
            
            range_min, range_max = 0, 255
            for num in nums:
                if num == '' or len(num) > 3:
                    return NEITHER
                          
                pos = num.find(filter)
                if pos != -1:
                    return NEITHER
                
                try:
                    intnum = int(num)
                except ValueError as err:
                    return NEITHER
                
                if not range_min <= intnum <= range_max:
                    return NEITHER
                
                if len(num) > 1 and num[0] == '0':
                    return NEITHER
            
            return "IPv4"
        
        def ipv6(ip: str):
            nums = ip.split(':')
            if len(nums) != 8:
                return NEITHER
            
            for num in nums:
                if num == '' or len(num) > 4:
                    return NEITHER
            
                pos = num.find(filter)
                if pos != -1:
                    return NEITHER
            
                try:
                    intnum = int(num, 16)
                except ValueError as err:
                    return NEITHER
            
            return "IPv6"
        
        if '.' in IP:
            return ipv4(IP)
        elif ':' in IP:
            return ipv6(IP)
        
        return NEITHER