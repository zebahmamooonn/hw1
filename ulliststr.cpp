#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(tail_ == nullptr || tail_->last == ARRSIZE){
    Item* newTail = new Item();
    newTail->first = 0;
    newTail->last = 1; 
    newTail->val[0] = val; 

    newTail->prev = tail_; 

    if(tail_ != nullptr){
      tail_->next = newTail;  
   }
    else{
      head_ = newTail; 
    }

  tail_ = newTail; 
  }
  else{
    tail_->val[tail_->last++] = val;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(head_==nullptr || head_->first == 0){

    Item* newHead = new Item();
    newHead->last = ARRSIZE; 
    newHead->first = ARRSIZE -1; 
    newHead->val[newHead->first] = val; 

    newHead->next=head_;
      if(head_!=nullptr){
        head_->prev = newHead;
      }
    head_= newHead; 

    if(tail_==nullptr){
      tail_=head_; 
    }
  }
  else{
    head_->first--;
    head_->val[head_->first] = val; 
  }
  size_++; 
}


void ULListStr::pop_back(){
  if(size_ ==0){
    return; 
  }
  tail_->last--;
  size_--; 
  if(tail_->first == tail_->last){
    Item* itemBefore = tail_->prev; 
    delete tail_; 
    tail_ = itemBefore; 
    if(itemBefore != nullptr){
      itemBefore->next = nullptr; 
    }
    else{
      head_ = nullptr;
    }
  }
}

void ULListStr::pop_front(){
  if(size_ ==0){
    return; 
  }
  head_->first++;
  size_--; 

  if(head_->first == head_->last){
    Item* newHead = head_->next; 
    delete head_; 
    head_ = newHead; 
    if(head_ != nullptr){
      head_->prev = nullptr; 
    }
    else{
      tail_ = nullptr;
    }
  }
}


std::string const& ULListStr::back() const{
  return tail_->val[tail_->last-1]; 
}

std::string const& ULListStr::front() const{
  return head_->val[head_->first]; 
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc>=size_){
    return nullptr; 
  }
  Item* currentItem = head_; 
  size_t currentIndex = 0; 

  while(currentItem != nullptr){
    size_t rangeIs = currentItem->last - currentItem->first; 
    
    if(loc < currentIndex + rangeIs){
      size_t indexNew = loc - currentIndex +currentItem->first;  
      return &(currentItem->val[indexNew]); 
    }
    currentIndex = currentIndex + rangeIs; 
    currentItem = currentItem->next; 
  }
  return nullptr; 
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


