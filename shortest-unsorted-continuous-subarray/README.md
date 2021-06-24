# Shortest Unsorted Continuous Subarray

## Problem

- คำอธิบาย

  - ใช้อาเรย์ที่กำหนดให้ (nums) หาขนาดของอารเรย์ย่อยที่ยังไม่ได้ถูกเรียงลำดับ

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ชุดของตัวเลข ซึ่งมีส่วนที่เรียงลำดับแล้วและมีส่วนที่ยังไม่ได้เรียงลำดับ

- ภาพรวมของปัญหา

  - แนวคิดเบื้องต้น :

    - วิธีแรก O(NLogN) คือใช้ฟังก์ชันการเรียงลำดับ สร้างลำดับที่ถูกต้อง จากนั้นหาตำแหน่งเริ่มต้นทางซ้ายที่ไม่ได้เรียงลำดับ และ จุดสิ้นสุดทางขวา จากนั้นนำมา ซึ่งเราจะรู้ว่าอาเรย์ตำแหน่งไหนถึงตำแหน่งไหนที่ยังไม่ได้เรียง และสามารถหาขนาดได้
    - วิธีที่สอง O(n) คือ ใช้การวนรอบทุกตัวเพื่อหาว่าเลขนั้นอยู่ในระดับที่เหมาะสมไหม เช่น 1,5,4 พบว่า 5 อยู่ในตำแหน่งไม่ถูกต้อง เพราะ 5 มากกว่า 4 ซึ่งคือตัวถัดไป ดังนั้นเราจะใช้ความคิดนี้ในการตรวจสอบทุกตัวและหาว่าเลขตัวน้อยที่สุด และ มากที่สุด ที่ไม่ถูกต้องคืออะไรจนครบ และเราจะสามารถรู้ตำแหน่งน้อยที่สุด และมากที่สุดของอาเรย์ที่ยังไม่เรียงและสามารถหาขนาดได้

  - การเขียนโปรแกรม : นำเสนอวิธีที่สอง
    - วนรอบเพื่อตรวจสอบเลขที่ผิดปกติหรือไม่
      - ถ้าผิดปกติ บันทึกค่าที่มากที่สุดไว้/น้อยที่สุดไว้
    - วนรอบ เพื่อหาตำแหน่งข้อมูลย่อยที่ผิดพลาดของตัวที่มากที่สุด/น้อยที่สุด
    - หาขนาดด้วยการ : ตัวมาก - ตัวน้อย + 1

## Solution

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int outOfArea (vector<int> nums, int i) {
    int num = nums[i];
    int lastPos = nums.size() - 1;
    if(i == 0){
        return num > nums[1];
    }
    if(i == lastPos){
        return num < nums[i - 1];
    }

    return num > nums[i + 1] || num < nums[i - 1];
}

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) {
        return 0;
    }

    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        if(outOfArea(nums, i)) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
    }

    if (minVal == INT_MAX){
        return 0;
    }
     int left = 0;

    while(minVal >= nums[left]) {
        left++;
        answer++;
    }

    int right = n - 1;

    while(maxVal <= nums[right]){
        right--;
    }

    return (right - left) + 1;
}

int main() {
    vector<int> nums ={1,2,3};
    cout << findUnsortedSubarray(nums);

}

```

### Ref

- https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
